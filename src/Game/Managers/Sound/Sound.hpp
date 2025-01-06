/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_SOUND_HPP_
#define RTYPE_GAME_MANAGERS_SOUND_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include <utility>
#include "GradeDe/Sound.hpp"
#include "GradeDe/Time.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Sound
            {
                public:
                    static Sound &get();
                    ~Sound() = default;

                    void setVolume(int volume);
                    void modifyVolume(int volume);
                    void play(const std::string &name);
                    void update();

                    int getVolume() const;

                private:
                    Sound();
                    std::unordered_map<std::string, std::unique_ptr<gd::Sound>> _sounds = {};
                    std::vector<std::pair<gd::Time, std::unique_ptr<gd::Sound>>> _playingList = {};
                    int _volume = 100;

                    void _addSound(const std::string &name, const std::string &path);
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_SOUND_HPP_ */
