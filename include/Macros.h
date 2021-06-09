#pragma once

#include <SFML/Graphics.hpp>

//--------------------Enum Section--------------------
enum ScreenType_t {MAIN_MENU, GAME_PLAY, EXIT};
enum Objects_t {PLAYER = 'P', ENEMY = 'E', WALL = '#', BOX = 'B', DOOR = 'D', KEY= 'K'};
enum ObjectsData_t {PLAYER_D, KEY_D, ENEMY_D};
enum Textures_t {PLAYER_T = 0, WALL_T, KEY_T, ENEMY_T, BOX_T, DOOR_T};
enum Sounds_t {};
enum class AnimationStatus_t{Idle, Run, Walk, Shoot, Hurt1, Hurt2, Jump, Death, Slide};

//--------------------Int Section--------------------
const std::pair<int,int> HOUSE_SIZE = {1000, 1000};
const std::pair<int,int> HOUSE_OBJECT_CAPACITY = {20, 20};
const int NUM_OF_TEXTURES = 3;
const int NUM_OF_ANIMATION = 2;
const int VELOCITY_ITERATIONS = 6;
const int POSITION_ITERATIONS = 2;

//--------------------String Section--------------------
const std::string HOUSES = "Houses.txt";

//--------------------Char Section--------------------
const char HOUSE_END = 'X';

//--------------------Float Section--------------------
const float TIME_STEP = 1.0f / 60.0f;


//--------------------Player Sprite Sheet Section--------------------
const auto IDLE_SIZE = sf::Vector2i(39, 40);
const auto RUN_SIZE = sf::Vector2i(44, 40);
const auto WALK_SIZE = sf::Vector2i(50, 40);
const auto SHOOT_SIZE = sf::Vector2i(45, 40);
const auto HIT1_SIZE = sf::Vector2i(45, 40);
const auto HIT2_SIZE = sf::Vector2i(40, 40);
const auto JUMP_SIZE = sf::Vector2i(43, 40);
const auto DEATH_SIZE = sf::Vector2i(40, 24);

//--------------------Key Sprite Sheet Section--------------------
const auto KEY_SIZE = sf::Vector2i(30, 50);
