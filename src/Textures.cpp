#include "Textures.h"

namespace {
    AnimationData playerData() {
        auto player = AnimationData{};

        player.m_data[AnimationStatus_t::Idle].emplace_back(55, 80, 361, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(542, 80, 351, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(58, 605, 363, 476);
        player.m_data[AnimationStatus_t::Idle].emplace_back(535, 606, 351, 476);

        player.m_data[AnimationStatus_t::Walk].emplace_back(1110, 50, 360, 450);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1572, 50, 421, 456);
        player.m_data[AnimationStatus_t::Walk].emplace_back(2174, 59, 409, 470);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1110, 50, 360, 450);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1108, 554, 365, 480);
        player.m_data[AnimationStatus_t::Walk].emplace_back(1602, 560, 397, 465);
        player.m_data[AnimationStatus_t::Walk].emplace_back(2150, 563, 403, 500);

        player.m_data[AnimationStatus_t::Jump].emplace_back(1126, 1298, 344, 365);
        player.m_data[AnimationStatus_t::Jump].emplace_back(1474, 1258, 283, 406);
        player.m_data[AnimationStatus_t::Jump].emplace_back(1802, 1218, 312, 376);

        player.m_data[AnimationStatus_t::Falling].emplace_back(1106, 1690, 295, 374);
        player.m_data[AnimationStatus_t::Falling].emplace_back(1411, 1723, 324, 336);
        player.m_data[AnimationStatus_t::Falling].emplace_back(1760, 1850, 300, 356);

        player.m_data[AnimationStatus_t::Shoot].emplace_back(52, 1258, 446, 482);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(539, 1260, 474, 482);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(59, 1784, 465, 480);
        player.m_data[AnimationStatus_t::Shoot].emplace_back(535, 1788, 455, 480);

        player.m_data[AnimationStatus_t::Death].emplace_back(58,2413,195,286);
        player.m_data[AnimationStatus_t::Death].emplace_back(357,2438,243,250);
        player.m_data[AnimationStatus_t::Death].emplace_back(717,2410,286, 234);
        player.m_data[AnimationStatus_t::Death].emplace_back(50,2772,285,246);
        player.m_data[AnimationStatus_t::Death].emplace_back(361,2772,282,246);
        player.m_data[AnimationStatus_t::Death].emplace_back(684,2775,294,211);
        player.m_data[AnimationStatus_t::Death].emplace_back(50,3087,291,212);
        player.m_data[AnimationStatus_t::Death].emplace_back(393,3087,292,212);
        player.m_data[AnimationStatus_t::Death].emplace_back(727,3087,325,212);

        return player;
    }

    AnimationData shootingEnemyData() {
        auto shootingEnemy = AnimationData{};

        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(32, 1, 281, 363);
        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(319, 1, 332, 365);
        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(671, 1, 319, 385);
        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(1, 418, 300, 398);
        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(333, 419, 304, 390);
        shootingEnemy.m_data[AnimationStatus_t::Walk].emplace_back(705, 418, 299, 415);


        shootingEnemy.m_data[AnimationStatus_t::Shoot].emplace_back(1031, 2, 362, 464);
        shootingEnemy.m_data[AnimationStatus_t::Shoot].emplace_back(1499, 2, 424, 464);
        shootingEnemy.m_data[AnimationStatus_t::Shoot].emplace_back(1001, 536, 443, 468);
        shootingEnemy.m_data[AnimationStatus_t::Shoot].emplace_back(1504, 536, 364, 466);
        
        shootingEnemy.m_data[AnimationStatus_t::Hurt].emplace_back(1055, 1079, 174, 302);

        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1055, 1079, 174, 302);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1342, 1100, 211, 283);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1663, 1127, 285, 218);

        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1002, 1418, 294, 195);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1358, 1420, 297, 195);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1700, 1442, 301, 171);

        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1002, 1680, 303, 173);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1337, 1683, 300, 171);
        shootingEnemy.m_data[AnimationStatus_t::Death].emplace_back(1700, 1683, 306, 171);
        

        return shootingEnemy;

    }

    AnimationData keyData() {
        auto key = AnimationData{};

        key.m_data[AnimationStatus_t::Idle].emplace_back(12, 19, 124, 240);
        key.m_data[AnimationStatus_t::Idle].emplace_back(152, 19, 122, 239);
        key.m_data[AnimationStatus_t::Idle].emplace_back(301, 19, 97, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(430, 20, 100, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(567, 22, 114, 234);
        key.m_data[AnimationStatus_t::Idle].emplace_back(706, 22, 126, 235);
        key.m_data[AnimationStatus_t::Idle].emplace_back(863, 21, 98, 236);
        key.m_data[AnimationStatus_t::Idle].emplace_back(987, 21, 100, 239);
        key.m_data[AnimationStatus_t::Idle].emplace_back(1121, 18, 122, 239);

        return key;
    }

    AnimationData knightEnemyData() {
        auto knightEnemyData = AnimationData{};
        
        knightEnemyData.m_data[AnimationStatus_t::Idle].emplace_back(10, 10, 108, 174);

        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(10, 10, 108, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(145, 8, 95, 176);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(280, 6, 81, 178);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(408, 1, 84, 183);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(536, 2, 80, 181);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(664, 2, 89, 180);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(17, 192, 103, 176);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(138, 194, 109, 173);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(273, 192, 95, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(410, 190, 81, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(536, 185, 85, 178);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(664, 186, 84, 177);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(24, 374, 89, 176);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(152, 376, 102, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(280, 378, 108, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(408, 376, 95, 176);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(536, 374, 84, 178);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(664, 369, 84, 183);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(24, 554, 84, 181);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(152, 555, 89, 180);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(280, 560, 102, 176);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(408, 562, 108, 173);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(536, 560, 95, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(664, 558, 81, 174);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(24, 737, 85, 178);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(152, 738, 85, 177);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(279, 739, 89, 175);
        knightEnemyData.m_data[AnimationStatus_t::Walk].emplace_back(401, 744, 101, 174);
        
        knightEnemyData.m_data[AnimationStatus_t::Hurt].emplace_back(10, 10, 108, 174);

        knightEnemyData.m_data[AnimationStatus_t::Death].emplace_back(10, 10, 108, 174);

        return knightEnemyData;
    }

    AnimationData elevatorData() {
        auto elevator = AnimationData{};

        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 61, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 215, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 368, 94, 93);
        elevator.m_data[AnimationStatus_t::Open].emplace_back(32, 523, 94, 93);

        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 523, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 368, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 215, 94, 93);
        elevator.m_data[AnimationStatus_t::Close].emplace_back(32, 61, 94, 93);

        return elevator;
    }

    AnimationData doorData() {
        auto door = AnimationData{};

        door.m_data[AnimationStatus_t::Open].emplace_back(192, 78, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 235, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 386, 48, 76);
        door.m_data[AnimationStatus_t::Open].emplace_back(192, 540, 48, 76);

        door.m_data[AnimationStatus_t::Close].emplace_back(192, 540, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 386, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 235, 48, 76);
        door.m_data[AnimationStatus_t::Close].emplace_back(192, 78, 48, 76);

        return door;
    }

    AnimationData hpGiftData() {
        auto hpGift = AnimationData{};

        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(68, 90, 197, 173);
        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(312, 92, 177, 179);
        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(540, 85, 144, 183);
        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(720, 89, 86, 187);
        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(840, 89, 135, 185);
        hpGift.m_data[AnimationStatus_t::Idle].emplace_back(1014, 89, 180, 180);

        return hpGift;
    }

    AnimationData lifeGiftData() {
        auto lifeGift = AnimationData{};

        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(892, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(1719, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(2562, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(3404, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(4234, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(3404, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(2562, 174, 627, 528);
        lifeGift.m_data[AnimationStatus_t::Idle].emplace_back(1719, 174, 627, 528);

        return lifeGift;
    }
}
//===========================
Textures::Textures() {
    m_textures.resize(NUM_OF_TEXTURES);
    m_BuildingsSprites.resize(NUM_OF_BUILDING);
    m_animationsData.resize(NUM_OF_ANIMATION);

    openTexture(PLAYER_T, "Player.png");
    openTexture(WALL_T, "Wall.png");
    openTexture(BOX_T, "Box.png");
    openTexture(KEY_T, "Key.png");
    openTexture(KNIGHT_ENEMY_T, "ThiefEnemy.png");
    openTexture(SHOOTER_ENEMY_T, "ShooterEnemy.png");
    openTexture(BULLET_T, "Bullet.png");
    openTexture(ELEVATOR_DOOR_T, "Elevator_Door.png");
    openTexture(STAT_BACKGROUND_T, "StatBackGround.png");
    openTexture(HP_GIFT_T, "HpGift.png");
    openTexture(LIFE_GIFT_T, "LifeGift.png");
    openTexture(BULLET_GIFT_T, "BulletGift.png");
    openTexture(MENU_BACK_GROUND, "MenuBackGround.png");
    openTexture(HOW_TO_PLAY_T, "HowToPlay.png");
    openTexture(WIN_T, "Win.png");
    openTexture(GAME_OVER_T, "GameOver.png");
    openTexture(LEVEL_UP_T, "LevelUp.png");
    openTexture(PAUSE_T, "Pause.png");

    openBuildingTexture(FirstHouse, "FirstHouse.png");
    openBuildingTexture(SecondHouse, "SecondHouse.png");
    openBuildingTexture(ThirdHouse, "ThirdHouse.png");
    openBuildingTexture(Room, "RoomBackGround.png");


    m_animationsData[PLAYER_D] = playerData();
    m_animationsData[KNIGHT_ENEMY_D] = knightEnemyData();
    m_animationsData[SHOOTER_ENEMY_D] = shootingEnemyData();
    m_animationsData[KEY_D] = keyData();
    m_animationsData[ELEVATOR_D] = elevatorData();
    m_animationsData[DOOR_D] = doorData();
    m_animationsData[HP_GIFT_D] = hpGiftData();
    m_animationsData[LIFE_GIFT_D] = lifeGiftData();
}
//=============================================================================
Textures& Textures::texturesObject() {
    static Textures texturesObject;

    return texturesObject;
}
//=============================================================================
void Textures::openTexture(Textures_t pos,const std::string & name) {
    if (!m_textures[pos].loadFromFile(name)) {
        throw std::runtime_error(name + " is missing");
    }
}
//=============================================================================
void Textures::openBuildingTexture(BuildingBackGround_t pos, const std::string & name) {
    if (!m_BuildingsSprites[pos].loadFromFile(name)) {
        throw std::runtime_error(name + " is missing");
    }
}
//=============================================================================
