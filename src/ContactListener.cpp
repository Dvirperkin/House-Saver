#include "ContactListener.h"
#include "Player.h"
#include "Key.h"
#include "Enemy.h"
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
                if (gameObjectB->getBodyType() == ENEMY) {
                    auto enemy = static_cast<Enemy*>(bodyUserDataB);
                    player->startContact(enemy);
                }
            }
        }
        if (gameObjectA->getBodyType() == ENEMY) {
            auto enemy = static_cast<Enemy*>(bodyUserDataA);
            
            if (bodyUserDataB) {
                auto gameObjectB = static_cast<GameObject*>(bodyUserDataB);

                if (gameObjectB->getBodyType() == BULLET) {
                    auto bullet = static_cast<Bullet *>(bodyUserDataB);
                    enemy->startContact(bullet);
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
                if (gameObjectA->getBodyType() == ENEMY)
                    player->startContact(static_cast<Enemy*>(bodyUserDataA));
            }
        }
        if (gameObjectB->getBodyType() == ENEMY) {
            auto enemy = static_cast<Enemy*>(bodyUserDataB);

            if (bodyUserDataA) {
                auto gameObjectA = static_cast<GameObject*>(bodyUserDataA);

                if (gameObjectA->getBodyType() == BULLET) {
                    auto bullet = static_cast<Bullet*>(bodyUserDataA);
                    enemy->startContact(bullet);
                }
            }
        }
    }


}
//=============================================================================
void ContactListener::EndContact(b2Contact *contact) {
    b2ContactListener::EndContact(contact);
}
//=============================================================================