#include "ContactListener.h"


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
            case THIEF_ENEMY:
            case SHOOTER_ENEMY:
                enemyStartContact(static_cast<Enemy *>(bodyUserDataA), gameObjectB);
                return;
            case BULLET:
                bulletStartContact(static_cast<Bullet *>(bodyUserDataA), gameObjectB);
            default:
                break;
        }

        switch (gameObjectB->getBodyType()) {
            case PLAYER:
                playerStartContact(static_cast<Player *>(bodyUserDataB), gameObjectA);
                return;
            case THIEF_ENEMY:
            case SHOOTER_ENEMY:
                enemyStartContact(static_cast<Enemy *>(bodyUserDataB), gameObjectA);
                return;
            case BULLET:
                bulletStartContact(static_cast<Bullet *>(bodyUserDataB), gameObjectA);

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
        case HP_GIFT:
            player->startContact(static_cast<HpGift *>(gameObject));
            break;
        case BULLET_GIFT:
            player->startContact(static_cast<BulletGift *>(gameObject));
            break;
        case LIFE_GIFT:
            player->startContact(static_cast<LifeGift *>(gameObject));
            break;
        case THIEF_ENEMY:
        case SHOOTER_ENEMY:
            player->startContact(static_cast<Enemy *>(gameObject));
            break;
        case DOOR:
            player->startContact(static_cast<Door *>(gameObject));
            break;
        case BULLET:
            player->startContact(static_cast<Bullet*>(gameObject));
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
void ContactListener::bulletStartContact(Bullet * bullet, GameObject * gameObject) {
    switch (gameObject->getBodyType()) {
        case WALL:
        case BOX:
            bullet->hit();
    }
}
//=============================================================================