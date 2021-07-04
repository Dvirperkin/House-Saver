#pragma once

#include <optional>

#include "StaticObject.h"

class Elevator : public StaticObject{
public:
    //--------------------Constructor/Destructor Section--------------------
    Elevator(const sf::Vector2f &, b2World &, const sf::Vector2f&);

    //--------------------Functions Section--------------------
    Objects_t getBodyType() const override {return ELEVATOR;}

    // Sets connects elevator.
    void setDestinationUP(std::shared_ptr<Elevator> elevator) {m_destinationUP = elevator;}
    void setDestinationDown(std::shared_ptr<Elevator> elevator) {m_destinationDown = elevator;}

    // Gets connects elevator positions.
    std::optional<b2Vec2> getElevatorDestinationUp() const;
    std::optional<b2Vec2> getElevatorDestinationDown() const;

    // Checks if the request elevator destination is valid.
    bool destinationUP() const {return m_destinationUP ? true : false;}
    bool destinationDown() const {return m_destinationDown ? true : false;}

    // Opens and closes elevator.
    void open() { setAnimationStatus(AnimationStatus_t::Open); }
    void close() { setAnimationStatus(AnimationStatus_t::Close); };

private:
    static bool m_registerIt;
    std::shared_ptr<Elevator> m_destinationUP = nullptr;
    std::shared_ptr<Elevator> m_destinationDown = nullptr;
};