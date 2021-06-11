#include "Textures.h"

namespace {
    AnimationData playerData() {
        const auto middleSpace = sf::Vector2i(1, 0);

        auto player = AnimationData{};
        auto currentStart = sf::Vector2i(6, 7);
        auto currentStart2 = sf::Vector2i(-6, 8);

        auto nextStart = [&](sf::Vector2i movementSize, sf::Vector2i middleSpace) {
            currentStart += middleSpace;
            currentStart.x += movementSize.x;
            return currentStart;
        };
        auto nextMovement = [&]() {
            currentStart.y += 47;
            currentStart.x = 0;
        };

        player.m_data[AnimationStatus_t::Idle].emplace_back(20,232,51,81);

        player.m_data[AnimationStatus_t::Walk].emplace_back(10,18,56,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(84,18,62,84);
        player.m_data[AnimationStatus_t::Walk].emplace_back(171,22,45,80);
        player.m_data[AnimationStatus_t::Walk].emplace_back(239,18,55,84);

        player.m_data[AnimationStatus_t::Jump].emplace_back(318,18,52,82);
        player.m_data[AnimationStatus_t::Jump].emplace_back(385,19,55,78);
        player.m_data[AnimationStatus_t::Jump].emplace_back(462,19,56,83);


        //player.m_data[AnimationStatus_t::Reload].emplace_back(20,232,51,81);
        //player.m_data[AnimationStatus_t::Reload].emplace_back(101,232,48,81);


        /*player.m_data[AnimationStatus_t::Idle].emplace_back(6,7,32,39);
        player.m_data[AnimationStatus_t::Idle].emplace_back(45,7,33,39);
        player.m_data[AnimationStatus_t::Idle].emplace_back(85,7,32,39);
        player.m_data[AnimationStatus_t::Idle].emplace_back(127,7,33,39);
        player.m_data[AnimationStatus_t::Idle].emplace_back(165,7,32,39);
        player.m_data[AnimationStatus_t::Idle].emplace_back(205,7,32,39);

        nextMovement();

        player.m_data[AnimationStatus_t::Walk].emplace_back(currentStart2, WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);
        player.m_data[AnimationStatus_t::Walk].emplace_back(nextStart(WALK_SIZE, middleSpace), WALK_SIZE);

        nextMovement();
        player.m_data[AnimationStatus_t::Jump].emplace_back(currentStart, JUMP_SIZE);
        player.m_data[AnimationStatus_t::Jump].emplace_back(nextStart(JUMP_SIZE, middleSpace), JUMP_SIZE);
        player.m_data[AnimationStatus_t::Jump].emplace_back(nextStart(JUMP_SIZE, middleSpace), JUMP_SIZE);
        player.m_data[AnimationStatus_t::Jump].emplace_back(nextStart(JUMP_SIZE, middleSpace), JUMP_SIZE);


        /*
        nextMovement();
        player.m_data[AnimationStatus_t::Run].emplace_back(currentStart, RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        player.m_data[AnimationStatus_t::Run].emplace_back(nextStart(RUN_SIZE, sf::Vector2i(1, 0)), RUN_SIZE);
        */
        return player;
    }

    AnimationData keyData() {
        const auto middleSpace = sf::Vector2i(0, 0);

        auto key = AnimationData{};
        auto currentStart = sf::Vector2i(0, 0);

        auto nextStart = [&](sf::Vector2i movementSize, sf::Vector2i middleSpace) {
            currentStart += middleSpace;
            currentStart.x += movementSize.x;
            return currentStart;
        };

        key.m_data[AnimationStatus_t::Idle].emplace_back(currentStart, KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);
        key.m_data[AnimationStatus_t::Idle].emplace_back(nextStart(KEY_SIZE, middleSpace), KEY_SIZE);

        return key;
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
    m_animationsData[PLAYER_D] = playerData();
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
