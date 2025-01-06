/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Sound.hpp"

namespace gd
{
    void Sound::load(const std::string &path)
    {
        if (!_buffer.loadFromFile(path))
            throw Error("Failed to load sound file: " + path);
        _sound.setBuffer(_buffer);
        _status = Stopped;
    }

    void Sound::play()
    {
        _sound.play();
        _status = Playing;
    }

    void Sound::pause()
    {
        _sound.pause();
        _status = Paused;
    }

    void Sound::stop()
    {
        _sound.stop();
        _status = Stopped;
    }

    void Sound::clear()
    {
        _sound.stop();
        _buffer.loadFromMemory(NULL, 0);
        _status = Unloaded;
    }

    void Sound::setLoop(bool loop)
    {
        _sound.setLoop(loop);
        _loop = loop;
    }

    void Sound::setVolume(float volume)
    {
        _sound.setVolume(volume);
        _volume = volume;
    }

    void Sound::setPitch(float pitch)
    {
        _sound.setPitch(pitch);
        _pitch = pitch;
    }

    Sound::Status Sound::getStatus() const
    {
        if (_status == Unloaded) return Unloaded;
        return static_cast<Status>(_sound.getStatus());
    }

    bool Sound::isLooping() const
    {
        return _loop;
    }

    float Sound::getVolume() const
    {
        return _volume;
    }

    float Sound::getPitch() const
    {
        return _pitch;
    }

    int Sound::getDuration() const
    {
        return _buffer.getDuration().asMilliseconds();
    }
} // namespace gd
