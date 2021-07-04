#pragma once

#include <SFML/Graphics.hpp>

//--------------------Using Section--------------------
using building = std::vector<std::string>;

using buildingDec = std::pair<building::const_iterator,
                              building::const_iterator>;

using buildingsDec = std::pair<std::vector<building>::const_iterator,
                               std::vector<building>::const_iterator>;

//--------------------Enum Section--------------------
// Object type enum.
enum Objects_t {
    PLAYER = 'P',
    THIEF_ENEMY = 'E',
    SHOOTER_ENEMY = 'T',
    WALL = '#',
    BOX = 'B',
    DOOR = 'D',
    KEY= 'K',
    BULLET ='*',
    ELEVATOR = '^',
    GIFT = 'G',
    HP_GIFT = '1',
    BULLET_GIFT = '2',
    LIFE_GIFT = '3'
};

enum ObjectsData_t {
    PLAYER_D,
    KEY_D,
    KNIGHT_ENEMY_D,
    SHOOTER_ENEMY_D,
    ELEVATOR_D,
    DOOR_D,
    HP_GIFT_D,
    LIFE_GIFT_D,
};

enum Shape_t {
    CIRCLE_SHAPE,
    POLYGON_SHAPE
};

enum Textures_t {
    PLAYER_T,
    WALL_T,
    BOX_T,
    KEY_T,
    KNIGHT_ENEMY_T,
    SHOOTER_ENEMY_T,
    BULLET_T,
    ELEVATOR_DOOR_T,
    STAT_BACKGROUND_T,
    HP_GIFT_T,
    LIFE_GIFT_T,
    BULLET_GIFT_T,
    MENU_BACK_GROUND,
    HOW_TO_PLAY_T,
    WIN_T,
    GAME_OVER_T,
    LEVEL_UP_T,
    PAUSE_T
};

enum BuildingBackGround_t {
    FirstHouse,
    SecondHouse,
    ThirdHouse,
    Room
};

enum PlayerStats_t {
    LIVE,
    HP,
    KEYS,
    SCORE
};

enum class AnimationStatus_t{
    Idle,
    Walk,
    Shoot,
    Hurt,
    Jump,
    Death,
    Falling,
    Open,
    Close
};

enum class Side_t{
    RIGHT,
    LEFT
};

enum class Building_t{
    HOUSE,
    ROOM
};

enum Sounds_t {
    LEVEL_UP_SOUND,
    BUTTON_CLICK_SOUND,
    GIFT_SOUND,
    DEATH_SOUND,
    SHOOT_SOUND,
    DOOR_SOUND,
    ELEVATOR_SOUND,
    PLAYER_HURT_SOUND,
    ENEMY_HURT_SOUND,
    PLAYER_JUMP_SOUND,

};

enum Music_t {
    MAIN_MENU_MUSIC,
    STAGE_MUSIC,
    WIN_MUSIC,
    GAME_OVER_MUSIC
};

//--------------------Int Section--------------------
const std::pair<int,int> WINDOW_SIZE = {1920, 1080};
const int CHARACTER_SIZE = 25;
const int NUM_OF_DETAILS = 4;
const int NUM_OF_TEXTURES = 18;
const int NUM_OF_BUILDING = 4;
const int NUM_OF_ANIMATION = 8;
const int NUM_OF_SOUNDS = 10;
const int NUM_OF_MUSICS = 4;
const int VELOCITY_ITERATIONS = 6;
const int POSITION_ITERATIONS = 2;
const int START_LIVES = 3;
const int MAX_LIVES = 5;
const int START_HP = 100;
const int SCORE_INCREASE = 50;
const int HP_INCREASE = 30;
const int NO_COMMAND = -1;

const int GIFT_HP = 0;
const int GIFT_BULLET = 1;
const int GIFT_LIFE = 2;

const int WIDTH_VIEW = 12;
const int HEIGHT_VIEW = 8;

const int DEATH_ANIMATION_TIME = 2;
const int BULLET_VELOCITY = 8;
const int ENEMY_BULLET_VELOCITY = 6;
const int TRANSITION_SCREEN_TIME = 6;
const int ENEMY_VELOCITY = 2;
const int PLAYER_ENEMY_RANGE = 10;
const int SHOOTING_RANGE = 300;

//--------------------String Section--------------------
const std::string HOUSES = "Houses.txt";

//--------------------Float Section--------------------
const sf::Vector2f ANTI_GRAVITY(0, -0.15f);
const float TIME_STEP = 1.0f / 60.0f;
const float HIT_MOVE = 9;
const float DELAY = 0.3f;
const float DESIRED_VEL = 5.f;
const float BULLET_DISTANCE = 0.7f;
const float FIRE_RATE = 0.4f;
const float ENEMY_FIRE_RATE = 0.7f;
const float START_BULLET_DAMAGE = 30.f;
const float VOLUME = 50;


const float MOVING_OBJECT_PHYSICAL_SIZE = 0.48f;


//--------------------Menu Button Section--------------------
const int BUTTON_WIDTH = WINDOW_SIZE.first / 3;
const int BUTTON_HEIGHT = 100;
const int BUTTON_CHAR_SIZE = 70;
const int THICKNESS = 7;
const int NO_THICKNESS = 0;
const int DO_NOTHING = -1;


const auto GRAY = sf::Color(150,150,150);