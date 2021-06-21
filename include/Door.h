#pragma once

#include "StaticObject.h"

class Building;
class BuildingDetails;

class Door : public StaticObject{
public:
    Door(const sf::Vector2f &, b2World &, const sf::Vector2f &,
         std::shared_ptr<Building> = nullptr);

    BuildingDetails runRoom(sf::RenderWindow&);

    void drawRoom(sf::RenderWindow& window, sf::Time deltaTime);

    void open() {setAnimationStatus(AnimationStatus_t::Open);}
    void close() {setAnimationStatus(AnimationStatus_t::Close);}

    Objects_t getBodyType() const override {return DOOR;}
    bool isRoom() const;

private:
    static bool m_registerIt;
    std::shared_ptr<Building> m_building = nullptr;
};