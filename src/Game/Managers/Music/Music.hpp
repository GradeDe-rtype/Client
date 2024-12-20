/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_MUSIC_HPP_
#define RTYPE_GAME_MANAGERS_MUSIC_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include "GradeDe/Music.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Music
            {
                public:
                    static Music &get();
                    ~Music() = default;

                    void setVolume(int volume);
                    void modifyVolume(int volume);
                    std::shared_ptr<gd::Music> getMusic();
                    void setMusic(const std::string &name);

                    int getVolume() const;

                private:
                    Music();
                    std::unordered_map<std::string, std::shared_ptr<gd::Music>> _musics = {};
                    std::shared_ptr<gd::Music> _currentMusic = nullptr;
                    int _volume = 0;

                    void _addMusic(const std::string &name, const std::string &path);
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_MUSIC_HPP_ */
