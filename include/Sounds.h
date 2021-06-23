#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "Macros.h"


class Sounds {

public:
    static Sounds & soundObject();
    void playSound(enum Sounds_t);
    void stopSound(enum Sounds_t);
    

    void playMusic(enum Music_t);
    void stopMusic(enum Music_t);
    

private:
    //--------------------Constructor/Destructor Section--------------------
    Sounds();
    Sounds(const Sounds &) = default;
    Sounds & operator=(const Sounds &) = default;

    bool checkSoundPlay(enum Sounds_t);
    bool checkMusicPlay(enum Music_t);

    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<sf::Sound> m_sounds;
    std::vector<std::unique_ptr<sf::Music>> m_musics;
};