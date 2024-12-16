/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_MUSIC_MANAGER_HPP_
#define RTYPE_Game_MUSIC_MANAGER_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include "GradeDe/Music.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Audio
        {
            class MusicManager
            {
                public:
                    MusicManager();
                    ~MusicManager() = default;

                    void setVolume(int volume);
                    void modifyVolume(int volume);
                    std::shared_ptr<gd::Music> getMusic();
                    void setMusic(const std::string &name);

                    int getVolume() const;

                private:
                    std::unordered_map<std::string, std::shared_ptr<gd::Music>> _musics = {};
                    std::shared_ptr<gd::Music> _currentMusic = nullptr;
                    int _volume = 100;

                    void _addMusic(const std::string &name, const std::string &path);
            };
        } // namespace Audio
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_MUSIC_MANAGER_HPP_ */
