#pragma once

#include "StaticObject.h"

class Elevator : public StaticObject{
public:

    Elevator(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    Objects_t getBodyType() const override {return ELEVATOR;}
    void setDestinationUP(std::shared_ptr<Elevator> elevator) {m_destinationUP = elevator;}
    void setDestinationDown(std::shared_ptr<Elevator> elevator) {m_destinationDown = elevator;}
    b2Vec2 getElevatorDestinationUp() const;
    b2Vec2 getElevatorDestinationDown() const;

    bool destinationUP() const {return m_destinationUP ? true : false;}
    bool destinationDown() const {return m_destinationDown ? true : false;}

    void open() { setAnimationStatus(AnimationStatus_t::Open); }
    void close() { setAnimationStatus(AnimationStatus_t::Close); };

private:
    static bool m_registerIt;
    std::shared_ptr<Elevator> m_destinationUP = nullptr;
    std::shared_ptr<Elevator> m_destinationDown = nullptr;
};