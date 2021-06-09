#include "Textures.h"

namespace {
    AnimationData playerData() {
        const auto size = sf::Vector2i(40, 40);
        const auto middleSpace = sf::Vector2i(1, 0);
        const auto middleSpace2 = sf::Vector2i(1, 0);

        auto player = AnimationData{};
        auto currentStart = sf::Vector2i(0, 8);
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

        player.m_data[Direction::Idle].emplace_back(currentStart, idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(idleSize, middleSpace), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(idleSize, middleSpace), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(idleSize, middleSpace), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(idleSize, middleSpace), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(idleSize, middleSpace), idleSize);

        nextMovement();

        player.m_data[Direction::Walk].emplace_back(currentStart2, walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(walkSize, middleSpace), walkSize);

        nextMovement();
        player.m_data[Direction::Jump].emplace_back(currentStart, jumpSize);
        player.m_data[Direction::Jump].emplace_back(nextStart(jumpSize, middleSpace), jumpSize);
        player.m_data[Direction::Jump].emplace_back(nextStart(jumpSize, middleSpace), jumpSize);
        player.m_data[Direction::Jump].emplace_back(nextStart(jumpSize, middleSpace), jumpSize);

        /*player.m_data[Direction::Run].emplace_back(currentStart, runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);
        player.m_data[Direction::Run].emplace_back(nextStart(runSize, sf::Vector2i(1, 0)), runSize);




        nextMovement();
        nextMovement();
        nextMovement();
        nextMovement();
        //nextMovement();

        player.m_data[Direction::Jump].emplace_back(currentStart, jumpSize);
        player.m_data[Direction::Jump].emplace_back(nextStart(jumpSize, middleSpace2), jumpSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(jumpSize, middleSpace2), jumpSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(jumpSize, middleSpace2), jumpSize);
        */
        return player;
    }
}

Textures::Textures() {
    m_textures.resize(NUM_OF_TEXTURES);
    m_animationsData.resize(NUM_OF_ANIMATION);

    if (!m_textures[PLAYER_T].loadFromFile("Player.png")) {
        throw std::runtime_error("Can't load file");
    }
    if (!m_textures[WALL_T].loadFromFile("Wall.png")) {
        throw std::runtime_error("Can't load file");
    }

    m_animationsData[PLAYER_D] = playerData();
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
