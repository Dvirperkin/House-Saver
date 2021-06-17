#pragma once

#include <SFML/Graphics.hpp>

//--------------------Using Section--------------------
using building = std::vector<std::string>;

using buildingDec = std::pair<building::const_iterator,
                building::const_iterator>;

using buildingsDec = std::pair<std::vector<building>::const_iterator,
        std::vector<building>::const_iterator>;

//--------------------Enum Section--------------------
enum ScreenType_t {MAIN_MENU, GAME_PLAY, EXIT};
enum Objects_t {PLAYER = 'P', ENEMY = 'E', WALL = '#', BOX = 'B', DOOR = 'D', KEY= 'K', BULLET ='*'};
enum ObjectsData_t {PLAYER_D, KEY_D, ENEMY_D, BULLET_D};
enum Textures_t {PLAYER_T = 0, WALL_T, BOX_T, KEY_T, ENEMY_T, BULLET_T, DOOR_T};
enum Sounds_t {};
enum class AnimationStatus_t{Idle, Walk, Shoot, Melee, Hurt, Jump, Death, Slide, Falling};
enum class Side_t{RIGHT, LEFT};
enum class Building_t{HOUSE, ROOM};

//--------------------Int Section--------------------
const std::pair<int,int> WINDOW_SIZE = {1000, 1000};
const std::pair<int,int> HOUSE_OBJECT_CAPACITY = {30, 20};
const int NUM_OF_TEXTURES = 6;
const int NUM_OF_ANIMATION = 4;
const int VELOCITY_ITERATIONS = 6;
const int POSITION_ITERATIONS = 2;

//--------------------String Section--------------------
const std::string HOUSES = "Houses.txt";

//--------------------Char Section--------------------
const char HOUSE_END = 'X';

//--------------------Float Section--------------------
const float TIME_STEP = 1.0f / 60.0f;


//--------------------Player Sprite Sheet Section--------------------
const auto IDLE_SIZE = sf::Vector2i(33, 39);
const auto RUN_SIZE = sf::Vector2i(44, 40);
const auto WALK_SIZE = sf::Vector2i(50, 40);
const auto SHOOT_SIZE = sf::Vector2i(45, 40);
const auto HIT1_SIZE = sf::Vector2i(45, 40);
const auto HIT2_SIZE = sf::Vector2i(40, 40);
const auto JUMP_SIZE = sf::Vector2i(43, 40);
const auto DEATH_SIZE = sf::Vector2i(40, 24);

//--------------------Key Sprite Sheet Section--------------------
const auto KEY_SIZE = sf::Vector2i(30, 50);

const float DESIREDVEL = 5.f;
const float BULLET_DISTANCE = 0.7f;
const float START_BULLET_DAMAGE = 100.f;
const float START_FIRE_RATE = 0.4f;
const sf::Vector2f ANTI_GRAVITY(0, -0.15f);
const float HIT_MOVE = 9;
