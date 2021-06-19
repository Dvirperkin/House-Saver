#include "Textures.h"

namespace {
    AnimationData playerData() {
        auto player = AnimationData{};

        player.m_data[AnimationStatus_t::Idle].emplace_back(55, 80, 361, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(542, 80, 351, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(58, 605, 363, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(535, 606, 351, 476);

        player.m_data[AnimationStatus_t::Walk].emplace_back(1110, 50, 360, 450);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1572, 50, 421, 456);
        player.m_data[AnimationStatus_t::Walk].emplace_back(2174, 59, 409, 470);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1110, 50, 360, 450);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1108, 554, 365, 480);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1602, 560, 397, 465);
        player.m_data[AnimationStatus_t::Walk].emplace_back(2150, 563, 403, 500);

        /*player.m_data[AnimationStatus_t::Melee].emplace_back(2739, 50, 350, 466);
        player.m_data[AnimationStatus_t::Melee].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Melee].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Melee].emplace_back(,,,);

        player.m_data[AnimationStatus_t::Shoot].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(,,,);*/

        player.m_data[AnimationStatus_t::Jump].emplace_back(1126, 1298, 344, 365);
        player.m_data[AnimationStatus_t::Jump].emplace_back(1474, 1258, 283, 406);
        player.m_data[AnimationStatus_t::Jump].emplace_back(1802, 1218, 312, 376);

        player.m_data[AnimationStatus_t::Falling].emplace_back(1106, 1690, 295, 374);
        player.m_data[AnimationStatus_t::Falling].emplace_back(1411, 1723, 324, 336);
        player.m_data[AnimationStatus_t::Falling].emplace_back(1760, 1850, 300, 356);

        player.m_data[AnimationStatus_t::Shoot].emplace_back(52, 1258, 446, 482);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(539, 1260, 474, 482);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(59, 1784, 465, 480);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(535, 1788, 455, 480);
        /*player.m_data[AnimationStatus_t::Hurt].emplace_back(,,,);

        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);
        player.m_data[AnimationStatus_t::Death].emplace_back(,,,);*/



        /*player.m_data[AnimationStatus_t::Idle].emplace_back(20,232,51,81);

        player.m_data[AnimationStatus_t::Walk].emplace_back(10,18,56,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(84,18,62,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(171,22,45,80);
        player.m_data[AnimationStatus_t::Walk].emplace_back(239,18,55,84);

        player.m_data[AnimationStatus_t::Jump].emplace_back(318,18,52,82);
        //player.m_data[AnimationStatus_t::Jump].emplace_back(385,19,55,78);

        player.m_data[AnimationStatus_t::Falling].emplace_back(462,19,56,83);*/


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

    AnimationData elevatorData() {
        auto elevator = AnimationData{};

        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 61, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 215, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 368, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 523, 94, 93);

        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 523, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 368, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 215, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 61, 94, 93);

        return elevator;
    }

    AnimationData doorData() {
        auto door = AnimationData{};

        door.m_data[AnimationStatus_t::Open].emplace_back(192, 78, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 235, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 386, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 540, 48, 76);

        door.m_data[AnimationStatus_t::Close].emplace_back(192, 540, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 386, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 235, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 78, 48, 76);

        return door;
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
    if (!m_textures[BULLET_T].loadFromFile("Bullet.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[ELEVATOR_DOOR_T].loadFromFile("Elevator_Door.png")) {
        throw std::runtime_error("Can't load file");
    }

    m_animationsData[PLAYER_D] = playerData();
    m_animationsData[ENEMY_D] = enemyData();
    m_animationsData[KEY_D] = keyData();
    m_animationsData[ELEVATOR_D] = elevatorData();
    m_animationsData[DOOR_D] = doorData();
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
