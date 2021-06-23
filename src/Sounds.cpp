#include "Sounds.h"

Sounds::Sounds(){
    m_soundBuffer.resize(NUM_OF_SOUNDS);
    m_sounds.resize(NUM_OF_SOUNDS);
    m_musics.resize(NUM_OF_MUSICS);

    //---Load Musics Section---

    m_musics[MAIN_MENU_MUSIC] = std::make_unique<sf::Music>();
    if (!m_musics[MAIN_MENU_MUSIC]->openFromFile("menu.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_musics[MAIN_MENU_MUSIC]->setLoop(true);

    m_musics[STAGE_MUSIC] = std::make_unique<sf::Music>();
    m_musics[STAGE_MUSIC]->openFromFile("StageMusic.ogg");
    if (!m_musics[STAGE_MUSIC]->openFromFile("StageMusic.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    //m_musics[STAGE_MUSIC]->setLoop(true);

    //---Load Sounds Section---

    
    /*if (m_soundBuffer[WIN_SOUND].loadFromFile("Victory.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[WIN_SOUND].setBuffer(m_soundBuffer[WIN_SOUND]);
    
    
    if (m_soundBuffer[GAME_OVER_SOUND].loadFromFile("GameOver.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[GAME_OVER_SOUND].setBuffer(m_soundBuffer[GAME_OVER_SOUND]);
    
    if (m_soundBuffer[LEVEL_UP_SOUND].loadFromFile("LevelUp.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[LEVEL_UP_SOUND].setBuffer(m_soundBuffer[LEVEL_UP_SOUND]);

    if (m_soundBuffer[SHOOT_SOUND].loadFromFile("shoot.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[SHOOT_SOUND].setBuffer(m_soundBuffer[SHOOT_SOUND]);
    */

    if (!m_soundBuffer[GIFT_SOUND].loadFromFile("collect.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[GIFT_SOUND].setBuffer(m_soundBuffer[GIFT_SOUND]);

    if (!m_soundBuffer[DEATH_SOUND].loadFromFile("death.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[DEATH_SOUND].setBuffer(m_soundBuffer[DEATH_SOUND]);

    if (!m_soundBuffer[DOOR_SOUND].loadFromFile("door.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[DOOR_SOUND].setBuffer(m_soundBuffer[DOOR_SOUND]);

    if (!m_soundBuffer[ELEVATOR_SOUND].loadFromFile("elevator.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[ELEVATOR_SOUND].setBuffer(m_soundBuffer[ELEVATOR_SOUND]);

    if (!m_soundBuffer[SHOOT_SOUND].loadFromFile("shoot.ogg")) {
        throw std::runtime_error("Can't load file");
    }
    m_sounds[SHOOT_SOUND].setBuffer(m_soundBuffer[SHOOT_SOUND]);

}
//=============================================================================
Sounds &Sounds::soundObject() {
    static Sounds soundObject;

    return soundObject;
}
//=============================================================================
void Sounds::playSound(enum Sounds_t sound){
    if (!checkSoundPlay(sound)) {
        m_sounds[sound].play();
        m_sounds[sound].setVolume(VOLUME * 2);
    }
}
//=============================================================================
void Sounds::stopSound(enum Sounds_t sound) {
    if(checkSoundPlay(sound))
        m_sounds[sound].stop();
}
//=============================================================================
bool Sounds::checkSoundPlay(enum Sounds_t sound) {

    if(m_sounds[sound].getStatus() == m_sounds[sound].Playing)
        return true;

    return false;
}
//=============================================================================
void Sounds::playMusic(enum Music_t music) {
    if (!checkMusicPlay(music)) {
        m_musics[music]->play();
        m_musics[music]->setVolume(VOLUME);
    }

}
//=============================================================================
void Sounds::stopMusic(enum Music_t music) {
    m_musics[music]->stop();
}
//=============================================================================
bool Sounds::checkMusicPlay(enum Music_t music) {

    if(m_musics[music]->getStatus() == m_musics[music]->Playing)
        return true;

    return false;
}
//=============================================================================
