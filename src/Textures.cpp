#include "Textures.h"

namespace {
    AnimationData playerData() {
        auto player = AnimationData{};


        /**/
        player.m_data[AnimationStatus_t::Idle].emplace_back(20,232,51,81);

        player.m_data[AnimationStatus_t::Walk].emplace_back(10,18,56,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(84,18,62,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(171,22,45,80);
        player.m_data[AnimationStatus_t::Walk].emplace_back(239,18,55,84);

        player.m_data[AnimationStatus_t::Jump].emplace_back(318,18,52,82);
        //player.m_data[AnimationStatus_t::Jump].emplace_back(385,19,55,78);

        player.m_data[AnimationStatus_t::Falling].emplace_back(462,19,56,83);


        return player;
    }

    AnimationData keyData() {
        auto key = AnimationData{};

        key.m_data[AnimationStatus_t::Idle].emplace_back(12, 19, 124, 240);
        key.m_data[AnimationStatus_t::Idle].emplace_back(152, 19, 122, 239);
        key.m_data[AnimationStatus_t::Idle].emplace_back(301, 19, 97, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(430, 20, 100, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(567, 22, 114, 234);
        key.m_data[AnimationStatus_t::Idle].emplace_back(706, 22, 126, 235);
        key.m_data[AnimationStatus_t::Idle].emplace_back(863, 21, 98, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(987, 21, 100, 239);
        key.m_data[AnimationStatus_t::Idle].emplace_back(1121, 18, 122, 239);

        return key;
    }
    AnimationData enemyData() {
        auto enemy = AnimationData{};

        enemy.m_data[AnimationStatus_t::Idle].emplace_back(33, 4, 811, 562);

        enemy.m_data[AnimationStatus_t::Walk].emplace_back(33,4,811, 562);

        return enemy;

    }
}
//===========================
Textures::Textures() {
    m_textures.resize(NUM_OF_TEXTURES);
    m_animationsData.resize(NUM_OF_ANIMATION);

    if (!m_textures[PLAYER_T].loadFromFile("Player.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[WALL_T].loadFromFile("Wall.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[BOX_T].loadFromFile("Box.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[KEY_T].loadFromFile("Key.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[ENEMY_T].loadFromFile("Enemy.png")) {
        throw std::runtime_error("Can't load file");
    }
    m_animationsData[PLAYER_D] = playerData();
    m_animationsData[ENEMY_D] = enemyData();
    m_animationsData[KEY_D] = keyData();
}
//=============================================================================
Textures& Textures::texturesObject() {
    static Textures texturesObject;

    return texturesObject;
}
//=============================================================================
const sf::Texture& Textures::getTexture(enum Textures_t image) {
    return m_textures[image];
}
//=============================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=============================================================================
