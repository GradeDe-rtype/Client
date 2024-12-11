/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "MusicManager.hpp"

namespace RType
{
    namespace Display
    {
        namespace Audio
        {
            MusicManager::MusicManager()
            {
                _addMusic("menu", "assets/music/Neon Frenzy.mp3");
                _addMusic("game", "assets/music/Adrenaline Surge.mp3");
            }

            void MusicManager::setMusic(const std::string &name)
            {
                if (_currentMusic)
                    _currentMusic->stop();
                _currentMusic = _musics[name];
                _currentMusic->setVolume(_volume);
                _currentMusic->play();
            }

            void MusicManager::setVolume(int volume)
            {
                _volume = volume;
                if (_currentMusic)
                    _currentMusic->setVolume(volume);
            }

            void MusicManager::modifyVolume(int volume)
            {
                _volume += volume;
                if (_volume < 0) _volume = 0;
                if (_volume > 100) _volume = 100;
                if (_currentMusic) _currentMusic->setVolume(_volume);
            }

            std::shared_ptr<gd::Music> MusicManager::getMusic()
            {
                return _currentMusic;
            }

            int MusicManager::getVolume() const
            {
                return _volume;
            }

            void MusicManager::_addMusic(const std::string &name, const std::string &path)
            {
                _musics[name] = std::make_shared<gd::Music>();
                _musics[name]->load(path);
            }
        } // namespace Audio
    } // namespace Display
} // namespace RType
