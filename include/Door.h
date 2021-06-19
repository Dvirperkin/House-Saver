#pragma once

#include "StaticObject.h"
#include "Room.h"

class Door : public StaticObject{
public:
    Door(const sf::Vector2f &, b2World &);

    void setRoom(Room &);

    void open() {setAnimationStatus(AnimationStatus_t::Open);}
    void close() {setAnimationStatus(AnimationStatus_t::Close);}

    Objects_t getBodyType() const override {return DOOR;}

private:
    static bool m_registerIt;
    Room * m_room = nullptr;
};