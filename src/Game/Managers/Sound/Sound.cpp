/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Sound.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Sound &Sound::get()
            {
                static Sound instance;
                return instance;
            }

            Sound::Sound()
            {
                _addSound("blaster", "assets/sound/blaster.mp3");
                _addSound("beep", "assets/sound/beep.mp3");
                _addSound("error", "assets/sound/error.mp3");
            }

            void Sound::setVolume(int volume)
            {
                _volume = volume;
                for (auto &sound : _sounds)
                    sound.second->setVolume(volume);
                for (auto &sound : _playingList)
                    sound.second->setVolume(volume);
            }

            void Sound::modifyVolume(int volume)
            {
                _volume += volume;
                if (_volume < 0) _volume = 0;
                if (_volume > 100) _volume = 100;
                setVolume(_volume);
            }

            void Sound::play(const std::string &name)
            {
                if (_sounds.find(name) == _sounds.end())
                    return;
                _playingList.push_back(std::make_pair<gd::Time, std::unique_ptr<gd::Sound>>(gd::Time(), std::make_unique<gd::Sound>(*_sounds[name])));
                _playingList.back().first.reset();
                _playingList.back().second->setVolume(_volume);
                _playingList.back().second->play();
            }

            void Sound::update()
            {
                for (auto it = _playingList.begin(); it != _playingList.end();) {
                    if (it->second->getStatus() == gd::Sound::Status::Stopped && it->first.getElapsedTime() >= it->second->getDuration())
                        it = _playingList.erase(it);
                    else
                        ++it;
                }
            }

            int Sound::getVolume() const
            {
                return _volume;
            }

            void Sound::_addSound(const std::string &name, const std::string &path)
            {
                _sounds[name] = std::make_unique<gd::Sound>();
                _sounds[name]->load(path);
                _sounds[name]->setVolume(_volume);
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType
