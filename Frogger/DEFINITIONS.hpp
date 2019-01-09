#pragma once

#define WINDOW_TITLE "Frogger"

//Original size 224*256
#define SCREEN_WIDTH 224*3
#define SCREEN_HEIGHT 256*3

#define TOP_ICON_FILEPATH "Resources/Images/topIcon.png"

#define FROG_FILEPATH "Resources/Images/Frog.png"
#define CARS_FILEPATH "Resources/Images/Cars.png"
#define PAD_FILEPATH "Resources/Images/Pad.png"
#define GOAL_FILEPATH "Resources/Images/Goal.png"
#define DEATH_FILEPATH "Resources/Images/Death.png"
#define LOG_FILEPATH "Resources/Images/Logs.png"
#define TURTLE_FILEPATH "Resources/Images/Turtle.png"
#define GOAL_FROG_FILEPATH "Resources/Images/GoalFrog.png"
#define HP_FILEPATH "Resources/Images/HP.png"

#define START_MUSIC_FILEPATH "Resources/Sounds/Stage_Start.ogg"
#define THEME_MUSIC_FILEPATH "Resources/Sounds/Stage_Theme.ogg"
#define FROG_HOMED_01_FILEPATH "Resources/Sounds/Frogger_Homed_01.ogg"
#define FROG_HOMED_02_FILEPATH "Resources/Sounds/Frogger_Homed_02.ogg"
#define FROG_HOMED_03_FILEPATH "Resources/Sounds/Frogger_Homed_03.ogg"
#define FROG_HOMED_04_FILEPATH "Resources/Sounds/Frogger_Homed_04.ogg"
#define FROG_HOMED_05_FILEPATH "Resources/Sounds/Frogger_Homed_05.ogg"
#define GAME_OVER_MUSIC_FILEPATH "Resources/Sounds/Game_Over.ogg"
#define JUMP_SOUND_FILEPATH "Resources/Sounds/sound-frogger-hop.ogg"
#define SQUASH_SOUND_FILEPATH "Resources/Sounds/sound-frogger-squash.ogg"
#define PLUNK_SOUND_FILEPATH "Resources/Sounds/sound-frogger-plunk.ogg"
#define TIME_SOUND_FILEPATH "Resources/Sounds/sound-frogger-time.ogg"


#define FONT_FILEPATH "Resources/Fonts/font.ttf"

#define HIGH_SCORE_FILEPATH "Resources/highScore.txt"


#define TILE_SIZE 48

#define MAX_LIFES 6

#define TIME 30


#define FROG_IDLE sf::IntRect(48, 0, 12, 14)
#define FROG_JUMP_01 sf::IntRect(24, 0, 12, 14)
#define FROG_JUMP_02 sf::IntRect(0, 0, 12, 14)

#define FROG_DEATH_01 sf::IntRect(33, 2, 12, 12)
#define FROG_DEATH_02 sf::IntRect(56, 1, 14, 14)
#define FROG_DEATH_03 sf::IntRect(79, 0, 16, 16)
#define FROG_DEATH_04 sf::IntRect(0, 0, 15, 16)

#define GOAL_FROG_01 sf::IntRect(0, 0, 16, 16)
#define GOAL_FROG_02 sf::IntRect(24, 0, 16, 16)

#define CAR_01 sf::IntRect(0, 0, 16, 14)
#define CAR_02 sf::IntRect(25, 1, 14, 12)
#define CAR_03 sf::IntRect(89, 2, 15, 10)
#define CAR_04 sf::IntRect(112, 0, 16, 14)
#define CAR_05 sf::IntRect(51, 2, 27, 10)

#define LOG_01 sf::IntRect(0, 0, 42, 10)
#define LOG_02 sf::IntRect(44, 0, 54, 10)
#define LOG_03 sf::IntRect(100, 0, 75, 10)

#define TURTLE_01 sf::IntRect(0, 2, 13, 9)
#define TURTLE_02 sf::IntRect(23, 1, 15, 11)
#define TURTLE_03 sf::IntRect(47, 1, 15, 11)

#define TURTLE_UPSIDEDOWN_01 sf::IntRect(82, 1, 10, 10)
#define TURTLE_UPSIDEDOWN_02 sf::IntRect(104, 0, 14, 13)



enum class Dir { Up, Down, Right, Left };
