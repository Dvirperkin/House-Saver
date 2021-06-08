#include "Textures.h"

namespace {
    AnimationData playerData() {
        const auto size = sf::Vector2i(40, 40);
        const auto middleSpace = sf::Vector2i(0, 0);

        auto player = AnimationData{};
        auto currentStart = sf::Vector2i(0, 0);

        auto nextStart = [&]() {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };
        auto nextMovement = [&](){
            currentStart.y += size.y;
            currentStart.x = 0;
        };

        player.m_data[Direction::Idle].emplace_back(currentStart, idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Idle].emplace_back(nextStart(), idleSize);

        nextMovement();

        player.m_data[Direction::Run].emplace_back(currentStart, idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Run].emplace_back(nextStart(), idleSize);

        nextMovement();

        player.m_data[Direction::Walk].emplace_back(currentStart, idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Walk].emplace_back(nextStart(), idleSize);

        nextMovement();

        player.m_data[Direction::Shoot].emplace_back(currentStart, idleSize);
        player.m_data[Direction::Shoot].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Shoot].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Shoot].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Shoot].emplace_back(nextStart(), idleSize);
        player.m_data[Direction::Shoot].emplace_back(nextStart(), idleSize);
        return player;
    }
}

Textures::Textures(){
    m_textures.resize(NUM_OF_TEXTURES);
    m_animationsData.resize(NUM_OF_ANIMATION);

    if(!m_textures[PLAYER_T].loadFromFile("Player.png")){
        throw std::runtime_error("Can't load file");
    }
    if(!m_textures[WALL_T].loadFromFile("Wall.png")){
        throw std::runtime_error("Can't load file");
    }

    m_animationsData[PLAYER_D] = playerData();
}
//=============================================================================
Textures & Textures::texturesObject(){
    static Textures texturesObject;

    return texturesObject;
}
//=============================================================================
const sf::Texture &Textures::getTexture(enum Textures_t image) {
    return m_textures[image];
}
//=============================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=============================================================================
