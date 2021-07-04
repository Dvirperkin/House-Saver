#pragma once

#include <SFML/Audio.hpp>
#include <memory>

#include "Macros.h"

// A singleton class that handle the game sounds resources.

class Sounds {

public:
    static Sounds & soundObject();
    void playSound(enum Sounds_t);
    void stopSound(enum Sounds_t);

    void setMusicMute(const bool);
    void setSoundMute(const bool);

    void playMusic(enum Music_t);
    void stopMusic(enum Music_t);

    bool soundStatus() const;
    bool musicStatus() const;

private:
    //--------------------Constructor/Destructor Section--------------------
    Sounds();
    Sounds(const Sounds &) = default;
    Sounds & operator=(const Sounds &) = default;

    bool checkSoundPlay(enum Sounds_t);
    bool checkMusicPlay(enum Music_t);
    bool m_muteMusic = false;
    bool m_muteSound = false;

    void loadMusic(Music_t, const std::string &);
    void loadSound(Sounds_t, const std::string &);
    std::vector<sf::Sound> m_sounds;
    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<std::unique_ptr<sf::Music>> m_musics;

};