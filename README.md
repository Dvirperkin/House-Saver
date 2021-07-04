The House Saver

Made By:

    Dvir Meir Perkin
    Yaniv Sonino
    Gal Meir Malka

Trailer:

    https://www.youtube.com/watch?v=szw5QofaR2w

General Description:

    This project is an implementation of an original game called The House Saver.

    The game is about a soldier left alone in the house and attacked by thieves and agents.
    The game implemented with SFML (Graphic library) and Box2D (Physics library).

Game Instructions:

    The main goal of the game is to collect all keys scattered around the different rooms of the house,
    and to kill all the enemies in the house.
                                                                                                                                       
    In order to control the player, the user can use the arrow keys or the {'W', 'A', 'S', 'D'} keys.
    In order to enter\exit a room the user can use the 'E' key.
    In order to use the elevator the user can use the 'W'\arrow up key to move up or 'S'\arrow down to move down.
    In order to commit suicide for some reason, the user can use the 'K' key.
    In order to shoot the user can use the left ctrl key.
    In order to jump the user can use the space key.

Design:

    The game world contains several objects:
    Player - Collect all the keys and kill all the enemies in the house. 
    Enemies - Chasing the player when he gets to thier floor to kill him.
    Box - Use to take a cover or to jump to higher floor.
    Gift - The player can collect this gift and get more hp and lives or to increase the power of his bullets.
    Elevator - The player can use the elevator to move between the floor of the house.
    Door - The player can enter to house's rooms through the doors.
    
    The rest of the objects are listed in files list.
    
Levels.txt:
    
    The stages of the game are in the file Houses.txt that in the resources folder.
    In order to add more stage the user can open this file and following this instructions:

    The first row in the file indicates the number of houses.
    Starting from the second line of the file the user can describe his houses.
    For each house the user need to specify the house width, height and the number of rooms in the house.
    For each room that described after the house the user need to specify only the room width and height.
    
    Example:
    1
    30 25 4
    ##############################
    #                            #
    #                            #
    # ^ K     T      G E  T GE D #
    ##############################
    #                            #
    #                            #
    # E  G B   T  G  E  K      ^ #
    ##############################
    #                            #
    #                          B #
    #G^     T       G    T    DG #
    ##############################
    #                            #
    #                            #
    #  D  T      G             ^ #
    ##############################
    #                            #
    #  K                         #
    #  ^               E   E  D  #
    ##############################
    #                            #
    #                            #
    # P   G            E       ^ #
    ##############################
    30 10
    ##############################
    #                            #
    #K  E BBT           G      ^ #
    ##############################
    #                            #
    # ^T               E  E     K#
    ##############################
    #  P                         #
    #  D   G       T          ^ T#
    ##############################
    20 10
    ####################
    #                  #
    #^ G BK#           #
    ########           #
    #                  #
    #           #^   EK#
    #           ########
    #  P               #
    #  D    E      TK ^#
    ####################
    20 10
    ####################
    #                  #
    #                  #
    #                  #
    #                  #
    #                  #
    #                  #
    #                P #
    #KE            G D #
    ####################
    12 10
    ############
    #          #
    #          #
    #          #
    #          #
    #          #
    #          #
    #  P       #
    #G D    K  #
    ############
    
    In this example the user build one house with 4 rooms.
    The house's width is 30 and the height is 25.
    The rooms described after the house.
    
    P - Player
    E - Thief Enemy
    T - Agent Enemy
    # - Wall\Floor
    B - Box
    D - Door
    ^ - Elevator
    K - Key
    G - Random Gift

Files list:

    Resources folder includes files that the program load for the game - textures, fonts, sounds and musics, the files 
    types are ogg, ttf and png.
    Animation.h , Animation.cpp - A class that manages the animation of each object. 
    AnimationData.h - An header that represent a struct that holds the sprites data of the animation.
    Audio.h , Audio.cpp - A class that implements a command in the menu that handles the in-game audio mute.
    Box.h , Box.cpp - A class that represents a box object.
    Building.h , Building.cpp - A class that representing a building inside the game.
    BuildingDetails.h - A class that responsible to show information about building's stats.
    Bullet.h , Bullet.cpp - A class that implements a gun bullets that reduce hp to moving objects.
    BulletGift.h , BulletGift.cpp - A derived class to implemnt greater bullet's damage.
    Button.h , Button.cpp - A class that implement a button.
    Command.h - An abstract class that represent a command in a menu.
    ContactListener.h , ContactListener.cpp - A class that handle with collisions in the physical world.
    Continue.h , Continue.cpp - A class that represent a continue command to continue the game.
    Door.h , Door.cpp - A class to implement a door which the player can go through to other rooms.
    Elevator.h , Elevator.cpp - A class to implement an elevator which the player can move between floors.
    Enemy.h , Enemy.cpp - An abstract class that represent an enemy.
    Exit.h , Exit.cpp - A class that represent a exit command to exit from the menu.
    Factory.h - A template class that implement factory for creating game objects.
    Font.h , Font.cpp - A singleton class that responsible for the font that used in the game.
    GameObject.h , GameObject.cpp - An abstract class that implements a game object.
    GamePlay.h , GamePlay.cpp - A class that represent a GamePlay command in the menu that start the game.
    Gift.h , Gift.cpp - An abstract class that represents a gift.
    HousesFile.h HousesFile.cpp - A class that represents a read-only file that manages all readings from the houses file according to the required protocol.
    HowToPlay.h , HowToPlay.cpp - A class that represent a HowToPlay command to display the game instructions.
    HpGift.h , HpGift.cpp - A derived class that implement an hp raise gift.
    Key.h , Key.cpp - A class that represent a key that the player needs to collect.
    ThiefEnemy.h , ThiefEnemy.cpp - A class that represent a thief enemy which can only attack by hand.
    LifeGift.h , LifeGift.cpp - A derived class that implement an extra life gift.
    Macros.h - A file that includes all the constant variables in the program.
    main.cpp - Responsible to run the game.
    Menu.h , Menu.cpp - A class that implements a menu according to command design pattern principles.
    MovingObject.h , MovingObject.cpp - An abstract class that represents a moving object.
    Player.h , Player.cpp - A class that represents the player.
    PlayerStats.h , PlayerStats.cpp - A class that responsible to show information about player's stats.
    QuitGame.h - A class that represent a QuitGame command to quit the game.
    Settings.h , Settings.cpp - A class that represent a Settings command that implement a sub menu of game settings.
    SFX.h , SFX.cpp - This class implements a command in the menu that handles the in-game SFX mute.
    ShooterEnemy.h , ShooterEnemy.cpp - A class that represent an agent enemy which can attack by shooting.
    Sounds.h , Sounds.cpp - A singleton class that responsible for all the sounds.
    StaticObject.h , StaticObject.cpp - An abstract class that represents a static object.
    TakenObject.h , TakenObject.cpp - An abstract class that represnt an objects that can be taken.
    Textures.h , Textures.cpp - A singleton class that responsible for all the textures that used.
    Wall.h , Wall.cpp - A class that represent a wall.
    Weapon.h , Weapon.cpp - A class that represent a weapon.

Main data structures and their role:


    std::vector<std::unique_ptr<Building>> m_house : A vector of unique_ptr to buildings, use to holds all the houses.
    std::vector<std::shared_ptr<Enemy>> m_enemies : A vector of shared_ptr to enemies, holds all the enemies in the house.
    std::vector<std::shared_ptr<Door>> m_doors : A vector of shared_ptr to Door, holds all the door to room in the house.
    std::vector<std::shared_ptr<Elevator>> m_elevators : A vector of shared_ptr to elevators, holds all the elevator in the house.
    std::vector<std::shared_ptr<TakenObject>> m_takenObjects : A vector of shared_ptr to takenObject, holds all the takenObject in the house.
    std::vector<std::vector<std::shared_ptr<StaticObject>>> m_staticObjects : A vector of shared_ptr to takenObject, holds all the takenObject in the house.

    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<AnimationStatus_t, ListType> : These two structure that holds all the information of an animation of object.

Worth Notes Algorithms:

    None

Known bugs:

    The player's animation is a bit distorted.
    A player or enemy standing on the corner of a box slides down - cause because the body of them is a circle. 

Other Comments:
    
    None