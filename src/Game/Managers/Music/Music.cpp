/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Music.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Music::Music()
            {
                _addMusic("menu", "assets/music/Neon Frenzy.mp3");
                _addMusic("settings", "assets/music/Neon Frenzy.mp3");
                _addMusic("game", "assets/music/Adrenaline Surge.mp3");
            }

            void Music::setMusic(const std::string &name)
            {
                if (_musics.find(name) == _musics.end()) return;
                if (_currentMusic)
                    _currentMusic->stop();
                _currentMusic = _musics[name];
                _currentMusic->setVolume(_volume);
                _currentMusic->play();
            }

            void Music::setVolume(int volume)
            {
                _volume = volume;
                if (_currentMusic)
                    _currentMusic->setVolume(volume);
            }

            void Music::modifyVolume(int volume)
            {
                _volume += volume;
                if (_volume < 0) _volume = 0;
                if (_volume > 100) _volume = 100;
                if (_currentMusic) _currentMusic->setVolume(_volume);
            }

            std::shared_ptr<gd::Music> Music::getMusic()
            {
                return _currentMusic;
            }

            int Music::getVolume() const
            {
                return _volume;
            }

            void Music::_addMusic(const std::string &name, const std::string &path)
            {
                _musics[name] = std::make_shared<gd::Music>();
                _musics[name]->load(path);
                _musics[name]->setVolume(_volume);
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType
