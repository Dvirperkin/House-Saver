#pragma once

#include "box2d/box2d.h"
#include "Player.h"
#include "Enemy.h"
#include "Elevator.h"
#include "Key.h"


class ContactListener : public b2ContactListener{
public:
    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;
private:

    void playerStartContact(Player *, GameObject *);
    void playerEndContact(Player *, GameObject *);

    void enemyStartContact(Enemy *, GameObject *);
    void enemyEndContact(Enemy *, GameObject *);
};
