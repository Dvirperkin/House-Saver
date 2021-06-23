configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Houses.txt ${CMAKE_BINARY_DIR} COPYONLY)

# Fonts
configure_file (impact.ttf ${CMAKE_BINARY_DIR} COPYONLY)

# Textures
configure_file (Player.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Wall.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Box.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Key.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (KnightEnemy.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (ShooterEnemy.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Bullet.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (Elevator_Door.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (StatBackGround.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (HpGift.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (LifeGift.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (BulletGift.png ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (MenuBackGround.png ${CMAKE_BINARY_DIR} COPYONLY)

# Sounds
configure_file (door.ogg ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (collect.ogg ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (death.ogg ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (elevator.ogg ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (shoot.ogg ${CMAKE_BINARY_DIR} COPYONLY)

#Music
configure_file (menu.ogg ${CMAKE_BINARY_DIR} COPYONLY)
configure_file (stageMusic.ogg ${CMAKE_BINARY_DIR} COPYONLY)