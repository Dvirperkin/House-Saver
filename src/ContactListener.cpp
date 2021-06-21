#include "ContactListener.h"
#include "Door.h"

void ContactListener::BeginContact(b2Contact *contact) {

    auto bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyUserDataA && bodyUserDataB) {
        auto gameObjectA = static_cast<GameObject *>(bodyUserDataA);
        auto gameObjectB = static_cast<GameObject *>(bodyUserDataB);

        switch (gameObjectA->getBodyType()) {
            case PLAYER:
                playerStartContact(static_cast<Player *>(bodyUserDataA), gameObjectB);
                return;
            case ENEMY:
                enemyStartContact(static_cast<Enemy *>(bodyUserDataA), gameObjectB);
                return;
            default:
                break;
        }

        switch (gameObjectB->getBodyType()) {
            case PLAYER:
                playerStartContact(static_cast<Player *>(bodyUserDataB), gameObjectA);
                return;
            case ENEMY:
                enemyStartContact(static_cast<Enemy *>(bodyUserDataB), gameObjectA);
                return;
            default:
                break;
        }
    }
}
//=============================================================================
void ContactListener::EndContact(b2Contact *contact) {
    auto bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyUserDataA && bodyUserDataB) {
        auto gameObjectA = static_cast<GameObject *>(bodyUserDataA);
        auto gameObjectB = static_cast<GameObject *>(bodyUserDataB);

        switch (gameObjectA->getBodyType()) {
            case PLAYER:
                playerEndContact(static_cast<Player *>(bodyUserDataA), gameObjectB);
                break;
            default:
                break;
        }

        switch (gameObjectB->getBodyType()) {
            case PLAYER:
                playerEndContact(static_cast<Player *>(bodyUserDataB), gameObjectA);
                break;
            default:
                break;
        }
    }
}
//=============================================================================
void ContactListener::playerStartContact(Player * player, GameObject * gameObject) {

    switch (gameObject->getBodyType()) {
        case KEY:
            player->startContact(static_cast<Key *>(gameObject));
            break;
        case ENEMY:
            player->startContact(static_cast<Enemy*>(gameObject));
            break;
        case DOOR:
            player->startContact(static_cast<Door *>(gameObject));
            break;
        case ELEVATOR:
            player->startContact(static_cast<Elevator *>(gameObject));
            break;
        default:
            break;
    }
}
//=============================================================================
void ContactListener::playerEndContact(Player * player, GameObject * gameObject) {

    switch (gameObject->getBodyType()) {
        case DOOR:
            player->endContact(static_cast<Door * >(gameObject));
            break;
        case ELEVATOR:
            player->endContact(static_cast<Elevator * >(gameObject));
            break;
    }
}
//=============================================================================
void ContactListener::enemyStartContact(Enemy * enemy, GameObject * gameObject) {

    switch (gameObject->getBodyType()) {
        case PLAYER:
            static_cast<Player *>(gameObject)->startContact(enemy);
            break;
        case BULLET:
            enemy->startContact(static_cast<Bullet *>(gameObject));
            break;
    }
}
//=============================================================================
void ContactListener::enemyEndContact(Enemy * enemy, GameObject * gameObject) {

}
//=============================================================================