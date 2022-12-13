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
        case LOAD_GAME_MENU:
        {
            Menu::DrawLoadGame();
            break;
        }
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
        case STATUS_MENU:
        {
            Menu::DrawExitMenu();
            break;
        }
        case PLAY_GAME:
        {
            frames %= 300;
            if (frames == 0) acceleration += 0.2;
            score ++;
            TrafficLightSecond--;
            if (TrafficLightSecond == -1){
                TrafficLight = (TrafficLight + 1)%3;
                if (TrafficLight == LIGHT_YELLOW) TrafficLightSecond = 180;
                if (TrafficLight == LIGHT_RED) TrafficLightSecond = 300;
                if (TrafficLight == LIGHT_GREEN) TrafficLightSecond = 600;
            }
            GameMap.Move();
            GameMap.MoveObjectX(TrafficLight, acceleration);
            GameMap.Fill();
            character[characterIndex].Move();
            character[characterIndex].Follow(GameMap, acceleration);
            Menu::DrawPlayGame();
            break;
        }
        case LOADING_PHASE:
        {
            LoadingSecond--;
            Menu::DrawLoadingPhase();
            break;
        }
        case LOSE_MENU:
        {
            Menu::DrawLoseMenu();
            break;
        }
        case LOAD_GAME_PLAY:
        {
            Menu::DrawLoadGameWhilePlay();
            break;
        }
        case SAVE_GAME:
        {
            Menu::DrawSaveGame();
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
void Game::SaveScore(){
    string FilePath = "../data/scoreboard.txt";
    ofstream fout;
    fout.open(FilePath);
    fout << record << '\n';
    fout << numScore << '\n';
    for (int i = 0; i < numScore; i ++){
        fout << UserScoreList[i] << '\n';
    }
    for (int i = 0; i < numScore; i ++){
        fout << ScoreList[i] << '\n';
    }
    for (int i = 0; i < numScore; i ++){
        fout << ScoreLevel[i] << '\n';
    }
    fout.close();
}
void Game::LoadScore(){
    string FilePath = "../data/scoreboard.txt";
    ifstream fin;
    fin.open(FilePath);
    fin >> record >> numScore;
    fin.ignore();
    ScoreList.clear();
    UserScoreList.clear();
    ScoreLevel.clear();
    for (int i = 0; i < numScore; i ++){
        string tmp;
        getline(fin, tmp);
        UserScoreList.push_back(tmp);
    }
    for (int i = 0; i < numScore; i ++){
        int tmp;
        fin >> tmp;
        ScoreList.push_back(tmp);
    }
    for (int i = 0; i < numScore; i ++){
        int tmp;
        fin >> tmp;
        ScoreLevel.push_back(tmp);
    }
    fin.close();
}