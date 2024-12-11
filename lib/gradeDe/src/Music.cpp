/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Music.hpp"

namespace gd
{
    void Music::load(const std::string &path)
    {
        if (!_music.openFromFile(path))
            throw gd::Error("Music::load", "Failed to load music from file: " + path);
        _status = Stopped;
    }

    void Music::play()
    {
        _music.play();
        _status = Playing;
    }

    void Music::pause()
    {
        _music.pause();
        _status = Paused;
    }

    void Music::stop()
    {
        _music.stop();
        _status = Stopped;
    }

    void Music::setLoop(bool loop)
    {
        _music.setLoop(loop);
        _loop = loop;
    }

    void Music::setVolume(float volume)
    {
        _music.setVolume(volume);
        _volume = volume;
    }

    void Music::setPitch(float pitch)
    {
        _music.setPitch(pitch);
        _pitch = pitch;
    }

    Music::Status Music::getStatus() const
    {
        return _status;
    }

    bool Music::isLooping() const
    {
        return _loop;
    }

    float Music::getVolume() const
    {
        return _volume;
    }

    float Music::getPitch() const
    {
        return _pitch;
    }
} // namespace gd
