/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_MUSIC_SFML_HPP_
#define GRADE_DE_MUSIC_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Audio.hpp>
#include "GradeDe/Error.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    class Music
    {
        public:
            enum Status {
                Unloaded,
                Stopped,
                Paused,
                Playing
            };

            Music() = default;
            ~Music() = default;

            void load(const std::string &path);
            void play();
            void pause();
            void stop();
            void clear();
            void setLoop(bool loop);
            void setVolume(float volume);
            void setPitch(float pitch);

            Status getStatus() const;
            bool isLooping() const;
            float getVolume() const;
            float getPitch() const;
            void *getMusic();

        private:
            sf::Music _music;
            Status _status = Unloaded;
            bool _loop = false;
            float _volume = 100;
            float _pitch = 1;
    };
} // namespace gd

#endif /* !GRADE_DE_FRAMERATE_SFML_HPP_ */
