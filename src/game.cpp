#include "game.h"
using namespace std;
void Game::run(bool& close){
    frames++;
    framesCharacter++;
    mousePosition = GetMousePosition();
    touchPosition = GetTouchPosition(0);
    SetMouseCursor(0);
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------
    switch (menu)
    {
        case MAIN_MENU:
        {
            Menu::DrawMainMenu();
            break;
        }
        case LEVEL_MENU:
        {
            level = 0;
            Menu::DrawLevelMenu();
            break;
        }
        // case 2:
        // {
            // load game 
        // }
        case SCOREBOARD:
        {
            Menu::DrawScoreboard();
            break;
        }
        case INSTRUCTIONS:
        {
            Menu::DrawInstructions();
            break;
        }
        case EXIT_MENU:
        {
            close = true;
            break;
        }
        case ENTER_NAME:
        {
            Menu::DrawEnterNamePhase();
            break;
        }
        case CHOOSE_CHARACTER:
        {
            Menu::DrawChooseCharacter();
            break;
        }
        // case STATUS_MENU:
        // {
            
        // }
        case PLAY_GAME:
        {
            score ++;
            TrafficLightSecond--;
            if (TrafficLightSecond == -1){
                TrafficLight = (TrafficLight + 1)%3;
                if (TrafficLight == LIGHT_YELLOW) TrafficLightSecond = 180;
                if (TrafficLight == LIGHT_RED) TrafficLightSecond = 300;
                if (TrafficLight == LIGHT_GREEN) TrafficLightSecond = 600;
            }
            GameMap.Move();
            GameMap.MoveObjectX(TrafficLight);
            GameMap.Fill();
            character[characterIndex].Move();
            Menu::DrawPlayGame();
            break;
        }
        default:
        {
            menu = 0;
            break;
        }
    }
    DrawFPS(10, 10);
}