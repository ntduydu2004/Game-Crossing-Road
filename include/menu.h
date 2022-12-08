#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "raylib.h"
#include "raygui.h"
#include "character.h"
#include "map.h"
typedef enum{
    MAIN_MENU = 0,
    LEVEL_MENU = 1,
    LOAD_GAME_MENU = 2,
    SCOREBOARD = 3,
    INSTRUCTIONS = 4,
    EXIT_MENU = 5,
    ENTER_NAME = 6,
    CHOOSE_CHARACTER = 7,
    STATUS_MENU = 8,
    PLAY_GAME = 9,
    LOADING_PHASE = 10,
    LOSE_MENU = 11,
}menuScreen;
class Menu{
protected:
    Texture2D background = LoadTexture("../data/image/Background/Background.png");
    Character character[3] =
    {
        Character("Ekko", (Vector2){GetScreenWidth() / 2 - 365, GetScreenHeight() / 2 - 125}),
        Character("Wukong", (Vector2){GetScreenWidth() / 2 - 65, GetScreenHeight() / 2 - 125}),
        Character("Samira", (Vector2){GetScreenWidth() / 2 + 235, GetScreenHeight() / 2 - 125}),
    };
    Map GameMap;
    short menu = 0, id = 0, characterIndex = 0; 
    short frames = 0, framesCharacter = 0;
    bool close = false, clearScoreBoard = true, touch = false;
    Vector2 mousePosition;
    Vector2 touchPosition;
    char name[30] = "\0";
    short indexMouse = -1, indexTouch = -1, choose, level = 0;
    int score = 0;
    short TrafficLightSecond = 0;
    short TrafficLight = 0;
    short LoadingSecond = 239;
    bool isCollided = false;
    Rectangle rec_Mode[5] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 40, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
    };
    Rectangle rec_Level[4] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 40, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50},
    };
    Rectangle rec_ScoreBoard[2] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    Rectangle rec_Instruction = {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50};
    Rectangle rec_EnterName[3] =
    {
        {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 25, 800, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    Rectangle rec_ChooseCharacter[5] =
    {
        {GetScreenWidth() / 2 - 425, GetScreenHeight() / 2 - 150, 250, 250},
        {GetScreenWidth() / 2 - 125, GetScreenHeight() / 2 - 150, 250, 250},
        {GetScreenWidth() / 2 + 175, GetScreenHeight() / 2 - 150, 250, 250},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    Rectangle rec_LoseMenu[2] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    // Rectangle rec_Exit[]
    
public:
    ~Menu();
    void DrawMainMenu();
    void DrawLevelMenu();
    void DrawExitMenu(); // appear if you lose/ want to exit
    void DrawLoseMenu();
    void DrawScoreboard();
    void DrawEnterNamePhase();
    void DrawLoadingPhase(); 
    void DrawInstructions();
    void DrawChooseCharacter();
    void DrawPlayGame();
    void Restart();
};