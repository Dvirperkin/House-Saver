#pragma once

#include "box2d/box2d.h"
#include "Macros.h"

#include "Player.h"

// A class that handle with collisions in the physical world.

class ContactListener : public b2ContactListener{
public:
    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;
private:

    void playerStartContact(Player *, GameObject *);
    void playerEndContact(Player *, GameObject *);

    void enemyStartContact(Enemy *, GameObject *);

    void bulletStartContact(Bullet *, GameObject *);
};
