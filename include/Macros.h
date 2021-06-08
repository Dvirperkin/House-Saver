#pragma once

#include <SFML/Graphics.hpp>

//--------------------Enum Section--------------------
enum ScreenType_t {MAIN_MENU, PLAY, EXIT};
enum Objects_t {PLAYER = 'P', ENEMY = 'E', WALL = '#', BOX = 'B', DOOR = 'D'};
enum ObjectsData_t {PLAYER_D, ENEMY_D};
enum Textures_t {PLAYER_T = 0, WALL_T, ENEMY_T, BOX_T, DOOR_T};
enum Sounds_t {};

//--------------------int Section--------------------
const std::pair<int,int> HOUSE_SIZE = {1000, 1000};
const std::pair<int,int> HOUSE_OBJECT_CAPACITY = {10, 10};
const int NUM_OF_TEXTURES = 2;
const int NUM_OF_ANIMATION = 1;
//const sf::IntRect PLAYER_SHEET = {0, 0, 37, 41};

//--------------------String Section--------------------
const std::string HOUSES = "Houses.txt";

//--------------------Char Section--------------------
const char HOUSE_END = 'X';


const float TIME_STEP = 1.0f / 60.0f;
const int VELOCITY_ITERATIONS = 6;
const int POSITION_ITERATIONS = 2;

//--------------------Player Sprite Sheet Section--------------------
const auto idleSize = sf::Vector2i(35, 40);
const auto runSize = sf::Vector2i(44, 40);
const auto walkSize = sf::Vector2i(37, 40);
const auto shootSize = sf::Vector2i(45, 40);
const auto hit1Size = sf::Vector2i(45, 40);
const auto hit2Size = sf::Vector2i(40, 40);
const auto jumpSize = sf::Vector2i(33, 40);
const auto deathSize = sf::Vector2i(40, 24);