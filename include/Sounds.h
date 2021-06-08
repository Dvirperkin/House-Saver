#pragma once

#include <SFML/Audio.hpp>
#include <memory>

#include "Macros.h"

class Sounds {

public:
    static Sounds & soundObject();
    void playSound(enum Sounds_t);
    void stopSound(enum Sounds_t);
    bool checkSoundPlay(enum Sounds_t);

private:
    //--------------------Constructor/Destructor Section--------------------
    Sounds();
    Sounds(const Sounds &) = default;
    Sounds & operator=(const Sounds &) = default;


    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<sf::Sound> m_sounds;
};