#include "Sounds.h"

Sounds::Sounds(){
    m_soundBuffer.resize(NUM_OF_SOUNDS);
    m_sounds.resize(NUM_OF_SOUNDS);
    m_musics.resize(NUM_OF_MUSICS);

    //---Load Musics Section---
    loadMusic(MAIN_MENU_MUSIC, "Menu.ogg");
    loadMusic(STAGE_MUSIC, "StageMusic.ogg");
    loadMusic(WIN_MUSIC, "Win.ogg");
    loadMusic(GAME_OVER_MUSIC, "GameOver.ogg");

    //---Load Sounds Section---
    loadSound(LEVEL_UP_SOUND, "LevelUp.ogg");
    loadSound(GIFT_SOUND, "collect.ogg");
    loadSound(DEATH_SOUND, "death.ogg");
    loadSound(DOOR_SOUND, "door.ogg");
    loadSound(ELEVATOR_SOUND, "elevator.ogg");
    loadSound(SHOOT_SOUND, "shoot.ogg");
    loadSound(PLAYER_HURT_SOUND, "playerHurt.ogg");
    loadSound(ENEMY_HURT_SOUND, "enemyHurt.ogg");
    loadSound(PLAYER_JUMP_SOUND, "playerJump.ogg");
    loadSound(BUTTON_CLICK_SOUND, "buttonClick.ogg");

}
//=============================================================================
Sounds &Sounds::soundObject() {
    static Sounds soundObject;

    return soundObject;
}
//=============================================================================
void Sounds::setMusicMute(const bool mute){

    if(mute){
        for(auto & music : m_musics){
            if(music->getStatus() == music->Playing)
                music->stop();
        }
    }

    m_muteMusic = mute;
}
//=============================================================================
void Sounds::setSoundMute(const bool mute){
    m_muteSound = mute;
}
//=============================================================================
void Sounds::playSound(enum Sounds_t sound){
    if (!checkSoundPlay(sound) && !m_muteSound) {
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
    if (!checkMusicPlay(music) && !m_muteMusic) {
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
bool Sounds::soundStatus()const {
    return m_muteSound;
}
//=============================================================================
bool Sounds::musicStatus()const {
    return m_muteMusic;
}
//=============================================================================
void Sounds::loadMusic(Music_t pos, const std::string & name) {
    m_musics[pos] = std::make_unique<sf::Music>();
    if (!m_musics[pos]->openFromFile(name)) {
        throw std::runtime_error(name + " is missing");
    }
    m_musics[pos]->setLoop(true);
}
//=============================================================================
void Sounds::loadSound(Sounds_t pos, const std::string & name) {
    if (!m_soundBuffer[pos].loadFromFile(name)) {
        throw std::runtime_error(name + " is missing");
    }
    m_sounds[pos].setBuffer(m_soundBuffer[pos]);
}
//=============================================================================