#include "Animation.h"

const auto AnimationTime = sf::seconds(0.1f);

Animation::Animation(const AnimationData& data, AnimationStatus_t status, sf::Sprite& sprite) :
                    m_data(data), m_status(status), m_sprite(sprite){
    update();
}

void Animation::setStatus(AnimationStatus_t status)
{
    if (m_status != status)
        m_index = 0;
    m_status = status;
    update();
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_status)->second.size();
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_status)->second[m_index]);

    m_sprite.setScale(HOUSE_SIZE.first / (m_sprite.getTextureRect().width * HOUSE_OBJECT_CAPACITY.first),
        HOUSE_SIZE.second / (m_sprite.getTextureRect().height * HOUSE_OBJECT_CAPACITY.second));

}
