#include "ContactListener.h"
#include "Player.h"
#include "Key.h"
#include <iostream>

void ContactListener::BeginContact(b2Contact *contact) {

    auto bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyUserDataA) {
        auto gameObjectA = static_cast<GameObject *>(bodyUserDataA);

        if (gameObjectA->getBodyType() == PLAYER) {
            auto player = static_cast<Player *>(bodyUserDataA);

            if (bodyUserDataB){
                auto gameObjectB = static_cast<GameObject *>(bodyUserDataB);

                if(gameObjectB->getBodyType() == KEY) {
                    auto key = static_cast<Key *>(bodyUserDataB);
                    player->startContact(key);
                }
            }
        }
    }

    if(bodyUserDataB) {
        auto gameObjectB = static_cast<GameObject *>(bodyUserDataB);
        if (gameObjectB->getBodyType() == PLAYER) {
            auto player = static_cast<Player *>(bodyUserDataB);

            if (bodyUserDataA){
                auto gameObjectA = static_cast<GameObject *>(bodyUserDataA);
                if(gameObjectA->getBodyType() == KEY)
                    player->startContact(static_cast<Key *>(bodyUserDataA));
            }
        }
    }


}
//=============================================================================
void ContactListener::EndContact(b2Contact *contact) {
    b2ContactListener::EndContact(contact);
}
//=============================================================================