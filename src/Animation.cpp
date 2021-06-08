#include "Animation.h"

const auto AnimationTime = sf::seconds(0.3f);

Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    update();
}

void Animation::direction(Direction dir)
{
    if (m_dir == dir || dir == Direction::Idle)
    {
        return;
    }

    m_dir = dir;
    update();
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);

    m_sprite.setScale(HOUSE_SIZE.first / (m_sprite.getTextureRect().width * HOUSE_OBJECT_CAPACITY.first),
                      HOUSE_SIZE.second / (m_sprite.getTextureRect().height * HOUSE_OBJECT_CAPACITY.second));
}