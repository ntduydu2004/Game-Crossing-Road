#define RAYGUI_IMPLEMENTATION
#include "menu.h"
using namespace std;
Menu::~Menu(){
    UnloadTexture(background);
}
void Menu::DrawMainMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_Mode[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[4]))
        {indexMouse = 5; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 5; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Mode[i])){
                menu = i + 1;
                break;
            }
        }
    }

    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Mode[0].x, rec_Mode[0].y, rec_Mode[0].width, rec_Mode[0].height, BLUE);
    DrawRectangle(rec_Mode[1].x, rec_Mode[1].y, rec_Mode[1].width, rec_Mode[1].height, BLUE);
    DrawRectangle(rec_Mode[2].x, rec_Mode[2].y, rec_Mode[2].width, rec_Mode[2].height, BLUE);
    DrawRectangle(rec_Mode[3].x, rec_Mode[3].y, rec_Mode[3].width, rec_Mode[3].height, BLUE);
    DrawRectangle(rec_Mode[4].x, rec_Mode[4].y, rec_Mode[4].width, rec_Mode[4].height, BLUE);
    if (indexMouse > 0){
        DrawRectangle(rec_Mode[indexMouse - 1].x, rec_Mode[indexMouse - 1].y, rec_Mode[indexMouse - 1].width, rec_Mode[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_Mode[indexMouse - 1].x, rec_Mode[indexMouse - 1].y, rec_Mode[indexMouse - 1].width, rec_Mode[indexMouse - 1].height, DARKBLUE);
    }

    DrawText("CROSSING ROAD", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 230, 50, MAROON);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("LOAD GAME", GetScreenWidth() / 2 - 85, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText("SCOREBOARD", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText("INSTRUCTION", GetScreenWidth() / 2 - 105, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawLevelMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_Level[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 4; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Level[i])){
                level = i + 1;
                break;
            }
        }
        if (level == 4) menu = 0;
        else if (level == 0) menu = 1;
        else menu = 6;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Level[0].x, rec_Level[0].y, rec_Level[0].width, rec_Level[0].height, BLUE);
    DrawRectangle(rec_Level[1].x, rec_Level[1].y, rec_Level[1].width, rec_Level[1].height, BLUE);
    DrawRectangle(rec_Level[2].x, rec_Level[2].y, rec_Level[2].width, rec_Level[2].height, BLUE);
    DrawRectangle(rec_Level[3].x, rec_Level[3].y, rec_Level[3].width, rec_Level[3].height, BLUE);
    if (indexMouse > 0){
        DrawRectangle(rec_Level[indexMouse - 1].x, rec_Level[indexMouse - 1].y, rec_Level[indexMouse - 1].width, rec_Level[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_Level[indexMouse - 1].x, rec_Level[indexMouse - 1].y, rec_Level[indexMouse - 1].width, rec_Level[indexMouse - 1].height, DARKBLUE);
    }
    

    DrawText("CHOOSE YOUR LEVEL", GetScreenWidth() / 2 - MeasureText("CHOOSE YOUR LEVEL", 50)/2, GetScreenHeight() / 2 - 230, 50, MAROON);
    DrawText(" EASY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("MEDIUM", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText(" HARD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawScoreboard(){
    if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[0])){
            numScore = 0;
            ScoreList.clear();
            UserScoreList.clear();
            ScoreLevel.clear();
            record = 0;
        }
        if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[1])) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    if (numScore) DrawRectangle(80, GetScreenHeight()/2 - 180, GetScreenWidth() - 160, 300, DARKBROWN);
    DrawRectangle(rec_ScoreBoard[0].x, rec_ScoreBoard[0].y, rec_ScoreBoard[0].width, rec_ScoreBoard[0].height, BLUE);
    DrawRectangle(rec_ScoreBoard[1].x, rec_ScoreBoard[1].y, rec_ScoreBoard[1].width, rec_ScoreBoard[1].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_ScoreBoard[indexMouse - 1].x, rec_ScoreBoard[indexMouse - 1].y, rec_ScoreBoard[indexMouse - 1].width, rec_ScoreBoard[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_ScoreBoard[indexMouse - 1].x, rec_ScoreBoard[indexMouse - 1].y, rec_ScoreBoard[indexMouse - 1].width, rec_ScoreBoard[indexMouse - 1].height, DARKBLUE);
    }
    if (numScore == 0){
        DrawText("THERE IS NO ACHIEVEMENT HERE!!", GetScreenWidth() / 2 - MeasureText("THERE IS NO ACHIEVEMENT HERE!!", 50)/2, GetScreenHeight() / 2 - 230, 50, MAROON);
    }
    else{
        DrawText("SCOREBOARD", GetScreenWidth() / 2 - MeasureText("SCOREBOARD", 50)/2, GetScreenHeight() / 2 - 290, 50, MAROON);
        DrawText(TextFormat("RECORD: %i", record), GetScreenWidth() / 2 - MeasureText(TextFormat("RECORD: %i", record), 30)/2, GetScreenHeight() / 2 - 230, 30, DARKPURPLE);
        for (int i = numScore - 1; i >= 0; i--){
            DrawText(TextFormat("%i", numScore - i), 100, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
            DrawText(UserScoreList[i].c_str(), 250, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
            if (ScoreLevel[i] == 1){
                DrawText("EASY", 650, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
            }
            if (ScoreLevel[i] == 2){
                DrawText("MEDIUM", 650, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
            }
            if (ScoreLevel[i] == 3){
                DrawText("HARD", 650, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
            }
            DrawText(TextFormat("%i", ScoreList[i]), 800, GetScreenHeight() / 2 - 220 + (numScore - i)*60, 30, RAYWHITE);
        }
    }
    DrawText(" CLEAR ", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawInstructions(){
    if (CheckCollisionPointRec(mousePosition, rec_Instruction))
        {indexMouse = 1; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Instruction)) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, BLUE);
    if (indexMouse){
        DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, DARKBLUE);
    }
    DrawText("USE W, A, S, D TO MOVE ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 230, 30, MAROON);
    DrawText("STAY AWAY FROM OBSTACLES !!! ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 180, 30, MAROON);
    DrawText("SURVIVE AS LONG AS POSSIBLE ^^ ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 130, 30, MAROON);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawEnterNamePhase(){
    if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])){
            indexTouch = 0;
            menu = 7; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2])){
            menu = 1;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                name[id] = (char)key;
                name[id + 1] = '\0';
                id++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            id--;
            if (id < 0)
                id = 0;
            name[id] = '\0';
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        indexTouch = 0;
        menu = 7;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_EnterName[0].x, rec_EnterName[0].y, rec_EnterName[0].width, rec_EnterName[0].height, DARKBLUE);
    DrawRectangle(rec_EnterName[1].x, rec_EnterName[1].y, rec_EnterName[1].width, rec_EnterName[1].height, BLUE);
    DrawRectangle(rec_EnterName[2].x, rec_EnterName[2].y, rec_EnterName[2].width, rec_EnterName[2].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("ENTER YOUR NAME", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, MAROON);
    DrawText(name, rec_EnterName[0].x + 10, rec_EnterName[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_EnterName[0].x + 13 + MeasureText(name, 30), rec_EnterName[0].y + 10, 30, RAYWHITE);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawChooseCharacter(){
    if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[4]))
        {indexMouse = 5; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsKeyPressed(KEY_ESCAPE)) menu = ENTER_NAME;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[0])) characterIndex = 0, indexTouch = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[1])) characterIndex = 1, indexTouch = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[2])) characterIndex = 2, indexTouch = 3;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[3])){
            acceleration = (level - 1)*2;
            LoadingSecond = 239;
            menu = LOADING_PHASE;
            character[characterIndex].namePlayer = (string)name;
            isCollided = false;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[4])) menu = 6;
        else indexTouch = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_ChooseCharacter[0].x, rec_ChooseCharacter[0].y, rec_ChooseCharacter[0].width, rec_ChooseCharacter[0].height, BLUE);
    DrawRectangle(rec_ChooseCharacter[1].x, rec_ChooseCharacter[1].y, rec_ChooseCharacter[1].width, rec_ChooseCharacter[1].height, BLUE);
    DrawRectangle(rec_ChooseCharacter[2].x, rec_ChooseCharacter[2].y, rec_ChooseCharacter[2].width, rec_ChooseCharacter[2].height, BLUE);
    DrawRectangle(rec_ChooseCharacter[3].x, rec_ChooseCharacter[3].y, rec_ChooseCharacter[3].width, rec_ChooseCharacter[3].height, BLUE);
    DrawRectangle(rec_ChooseCharacter[4].x, rec_ChooseCharacter[4].y, rec_ChooseCharacter[4].width, rec_ChooseCharacter[4].height, BLUE);
    if (1 <= indexMouse && indexMouse <= 3){
        DrawRectangle(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
    }
    else if (indexMouse >= 4) {
        DrawRectangle(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, DARKBLUE);
    }
    if (indexTouch){
        DrawRectangle(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE YOUR CHARACTER", GetScreenWidth() / 2 - MeasureText("CHOOSE YOUR CHARACTER", 50) / 2, GetScreenHeight() / 2 - 230, 50, MAROON);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    character[0].DrawChoose();
    character[1].DrawChoose();
    character[2].DrawChoose();
    EndDrawing();
}
void Menu::DrawPlayGame(){
    character[characterIndex].ChangeState(framesCharacter, GameMap);
    // if (character[characterIndex].position.y > camera.target.y + GetScreenHeight() - camera.offset.y - 60) character[characterIndex].position.y = camera.target.y + GetScreenHeight() - camera.offset.y - 60;
    if (IsKeyPressed(KEY_P)) menu = STATUS_MENU;
    if (IsKeyPressed(KEY_T)) menu = LOAD_GAME_PLAY;
    if (IsKeyPressed(KEY_L)) menu = SAVE_GAME;
    character[characterIndex].CheckCollisionObject(GameMap, isCollided);
    if (isCollided){
        menu = LOSE_MENU;
        score /= 3;
        ScoreList.push_back(score);
        UserScoreList.push_back(character[characterIndex].namePlayer);
        ScoreLevel.push_back(level);
        if (UserScoreList.back() == ""){
            UserScoreList.back() = "Nameless Player";
        }
        numScore ++;
        if (numScore > 5){
            numScore = 5;
            ScoreList.erase(ScoreList.begin());
            UserScoreList.erase(UserScoreList.begin());
            ScoreLevel.erase(ScoreLevel.begin());
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    DrawRectangle(10, 10, 250, 50, BLACK);
    DrawRectangle(10, 70, 250, 50, BLACK);
    if (TrafficLight == LIGHT_GREEN)
    DrawText(TextFormat("GREEN: %i", (TrafficLightSecond/60)), 20, 20, 30, GREEN);
    if (TrafficLight == LIGHT_RED)
    DrawText(TextFormat("RED: %i", (TrafficLightSecond/60)), 20, 20, 30, RED);
    if (TrafficLight == LIGHT_YELLOW)
    DrawText(TextFormat("YELLOW: %i", (TrafficLightSecond/60)), 20, 20, 30, YELLOW);
    DrawText(TextFormat("SCORE: %i", score/3), 20, 80, 30, VIOLET);
    EndDrawing();
}
void Menu::DrawLoadingPhase(){
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    if (LoadingSecond == 0){
        menu = PLAY_GAME;
        frames = 1;
    }
    if (LoadingSecond >= 60){
        DrawText(TextFormat("%i", LoadingSecond/60), GetScreenWidth()/2 - 100, GetScreenHeight()/2 - 200, 400, DARKBLUE);
    }
    else{
        DrawText("START!!!", GetScreenWidth()/2 - MeasureText("START!!!", 200)/2, GetScreenHeight()/2 - 100, 200, DARKBLUE);
    }
    EndDrawing();
}
void Menu::DrawLoseMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[1]))
        {indexMouse = 2; SetMouseCursor(4);}    
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0)){
        if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[0])){
            Restart();
            menu = LOADING_PHASE;
            return;
        }
        if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[1])){
            Restart();
            menu = MAIN_MENU;
            return;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    // DrawRectangle(GetScreenWidth()/2 - 420, GetScreenHeight()/2 - 250, 840, 500, BROWN);
    DrawRectangle(rec_LoseMenu[0].x, rec_LoseMenu[0].y, rec_LoseMenu[0].width, rec_LoseMenu[0].height, BLUE);
    DrawRectangle(rec_LoseMenu[1].x, rec_LoseMenu[1].y, rec_LoseMenu[1].width, rec_LoseMenu[1].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoseMenu[indexMouse - 1].x, rec_LoseMenu[indexMouse - 1].y, rec_LoseMenu[indexMouse - 1].width, rec_LoseMenu[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
    }
    DrawText("BETTER LUCK NEXT TIME^^", GetScreenWidth()/2 - MeasureText("BETTER LUCK NEXT TIME^^", 50)/2, GetScreenHeight()/2 - 25, 50, MAROON);
    if (score > record){
        DrawText("CONGRATULATIONS! YOU HAVE BEATEN THE RECORD", GetScreenWidth()/2 - MeasureText("CONGRATULATIONS! YOU HAVE BEATEN THE RECORD", 30)/2, GetScreenHeight()/2 + 55, 30, YELLOW);
    }
    DrawText(" RESTART ", GetScreenWidth() / 2 - MeasureText(" RESTART ", 30) / 2, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::Restart(){
    GameMap.Restart();
    LoadingSecond = 239;
    character[characterIndex].position = (Vector2){GetScreenWidth()/2 - 32, GetScreenHeight() - 200};
    character[characterIndex].moveside = character[characterIndex].movestate = 0;
    isCollided = false;
    if (record < score) record = score;
    score = 0;
    acceleration = (level - 1)*2;
}
void Menu::DrawExitMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_Exit[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Exit[1]))
        {indexMouse = 2; SetMouseCursor(4);}    
    else if (CheckCollisionPointRec(mousePosition, rec_Exit[2]))
        {indexMouse = 3; SetMouseCursor(4);}    
    else if (CheckCollisionPointRec(mousePosition, rec_Exit[3]))
        {indexMouse = 4; SetMouseCursor(4);}    
    else
        indexMouse = 0;
    
    if (IsMouseButtonPressed(0)){
        if (CheckCollisionPointRec(mousePosition, rec_Exit[0])){
            menu = PLAY_GAME;
        }
        if (CheckCollisionPointRec(mousePosition, rec_Exit[1])){
            Restart();
            menu = LOADING_PHASE;
        }
        if (CheckCollisionPointRec(mousePosition, rec_Exit[2])){
            menu = SAVE_GAME;
        }
        if (CheckCollisionPointRec(mousePosition, rec_Exit[3])){
            Restart();
            menu = MAIN_MENU;
        }
    }

    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    DrawRectangle(rec_Exit[0].x, rec_Exit[0].y, rec_Exit[0].width, rec_Exit[0].height, BLUE);
    DrawRectangle(rec_Exit[1].x, rec_Exit[1].y, rec_Exit[1].width, rec_Exit[1].height, BLUE);
    DrawRectangle(rec_Exit[2].x, rec_Exit[2].y, rec_Exit[2].width, rec_Exit[2].height, BLUE);
    DrawRectangle(rec_Exit[3].x, rec_Exit[3].y, rec_Exit[3].width, rec_Exit[3].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_Exit[indexMouse - 1].x, rec_Exit[indexMouse - 1].y, rec_Exit[indexMouse - 1].width, rec_Exit[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
    }
    DrawText(" RESUME ", GetScreenWidth() / 2 - MeasureText(" RESUME ", 30) / 2, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText(" RESTART ", GetScreenWidth() / 2 - MeasureText(" RESTART ", 30) / 2, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText(" SAVE ", GetScreenWidth() / 2 - MeasureText(" SAVE ", 30) / 2, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - MeasureText(" EXIT ", 30) / 2, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawLoadGame(){
    if (CheckCollisionPointRec(mousePosition, rec_LoadGame[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_LoadGame[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[1])){
            CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
            if (CanLoad){
                LoadGame();
                LoadingSecond = 239;
                menu = LOADING_PHASE;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[2])){
            menu = MAIN_MENU;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                FilePath.push_back((char)key);
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (FilePath.size())
            FilePath.pop_back();
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
        if (CanLoad){
            LoadGame();
            LoadingSecond = 239;
            menu = LOADING_PHASE;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_LoadGame[0].x, rec_LoadGame[0].y, rec_LoadGame[0].width, rec_LoadGame[0].height, DARKBLUE);
    DrawRectangle(rec_LoadGame[1].x, rec_LoadGame[1].y, rec_LoadGame[1].width, rec_LoadGame[1].height, BLUE);
    DrawRectangle(rec_LoadGame[2].x, rec_LoadGame[2].y, rec_LoadGame[2].width, rec_LoadGame[2].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoadGame[indexMouse - 1].x, rec_LoadGame[indexMouse - 1].y, rec_LoadGame[indexMouse - 1].width, rec_LoadGame[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_LoadGame[indexMouse - 1].x, rec_LoadGame[indexMouse - 1].y, rec_LoadGame[indexMouse - 1].width, rec_LoadGame[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE A FOLDER PATH TO LOAD", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, MAROON);
    DrawText(FilePath.c_str(), rec_LoadGame[0].x + 10, rec_LoadGame[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_LoadGame[0].x + 13 + MeasureText(FilePath.c_str(), 30), rec_LoadGame[0].y + 10, 30, RAYWHITE);
    DrawText(" LOAD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    if (!CanLoad){
        DrawText("*WRONG DIRECTORY", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 50, 20, RED);
    }
    EndDrawing();
}
void Menu::DrawLoadGameWhilePlay(){
    if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[3])){
        indexMouse = 4;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[1])){
            indexTouch = 0;
            menu = PLAY_GAME; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[2])){
            CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
            if (CanLoad){
                LoadGame();
                LoadingSecond = 239;
                menu = LOADING_PHASE;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[3])){
            Restart();
            menu = MAIN_MENU;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                FilePath.push_back((char)key);
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if(FilePath.size())
            FilePath.pop_back();
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
        if (CanLoad){
            LoadGame();
            LoadingSecond = 239;
            menu = LOADING_PHASE;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    DrawRectangle(GetScreenWidth()/2 - 420, GetScreenHeight()/2 - 150, 840, 500, BROWN);
    DrawRectangle(rec_LoadGameWhilePlay[0].x, rec_LoadGameWhilePlay[0].y, rec_LoadGameWhilePlay[0].width, rec_LoadGameWhilePlay[0].height, DARKBLUE);
    DrawRectangle(rec_LoadGameWhilePlay[1].x, rec_LoadGameWhilePlay[1].y, rec_LoadGameWhilePlay[1].width, rec_LoadGameWhilePlay[1].height, BLUE);
    DrawRectangle(rec_LoadGameWhilePlay[2].x, rec_LoadGameWhilePlay[2].y, rec_LoadGameWhilePlay[2].width, rec_LoadGameWhilePlay[2].height, BLUE);
    DrawRectangle(rec_LoadGameWhilePlay[3].x, rec_LoadGameWhilePlay[3].y, rec_LoadGameWhilePlay[3].width, rec_LoadGameWhilePlay[3].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoadGameWhilePlay[indexMouse - 1].x, rec_LoadGameWhilePlay[indexMouse - 1].y, rec_LoadGameWhilePlay[indexMouse - 1].width, rec_LoadGameWhilePlay[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_LoadGameWhilePlay[indexMouse - 1].x, rec_LoadGameWhilePlay[indexMouse - 1].y, rec_LoadGameWhilePlay[indexMouse - 1].width, rec_LoadGameWhilePlay[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE A FOLDER PATH TO LOAD", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, PINK);
    DrawText(FilePath.c_str(), rec_LoadGameWhilePlay[0].x + 10, rec_LoadGameWhilePlay[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_LoadGameWhilePlay[0].x + 13 + MeasureText(FilePath.c_str(), 30), rec_LoadGameWhilePlay[0].y + 10, 30, RAYWHITE);
    DrawText(" RESUME ", GetScreenWidth() / 2 - MeasureText(" RESUME ", 30)/2, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" LOAD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 270, 30, RAYWHITE);
    if (!CanLoad){
        DrawText("*WRONG DIRECTORY", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 50, 20, YELLOW);
    }
    EndDrawing();
}
void Menu::DrawSaveGame(){
    if (CheckCollisionPointRec(mousePosition, rec_SaveGame[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[3])){
        indexMouse = 4;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_SaveGame[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[1])){
            indexTouch = 0;
            menu = PLAY_GAME; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[2])){
            CanSave = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
            if (CanSave){
                SaveGame();
                Restart();
                indexTouch = 0;
                menu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, rec_SaveGame[3])){
            Restart();
            menu = MAIN_MENU;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                FilePath.push_back((char)key);
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (FilePath.size())
            FilePath.pop_back();
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        CanSave = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
        if (CanSave){
            SaveGame();
            Restart();
            indexTouch = 0;
            menu = MAIN_MENU;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    DrawRectangle(GetScreenWidth()/2 - 420, GetScreenHeight()/2 - 150, 840, 500, BROWN);
    DrawRectangle(rec_SaveGame[0].x, rec_SaveGame[0].y, rec_SaveGame[0].width, rec_SaveGame[0].height, DARKBLUE);
    DrawRectangle(rec_SaveGame[1].x, rec_SaveGame[1].y, rec_SaveGame[1].width, rec_SaveGame[1].height, BLUE);
    DrawRectangle(rec_SaveGame[2].x, rec_SaveGame[2].y, rec_SaveGame[2].width, rec_SaveGame[2].height, BLUE);
    DrawRectangle(rec_SaveGame[3].x, rec_SaveGame[3].y, rec_SaveGame[3].width, rec_SaveGame[3].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_SaveGame[indexMouse - 1].x, rec_SaveGame[indexMouse - 1].y, rec_SaveGame[indexMouse - 1].width, rec_SaveGame[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_SaveGame[indexMouse - 1].x, rec_SaveGame[indexMouse - 1].y, rec_SaveGame[indexMouse - 1].width, rec_SaveGame[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE A FOLDER PATH TO SAVE", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, PINK);
    DrawText(FilePath.c_str(), rec_SaveGame[0].x + 10, rec_SaveGame[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_SaveGame[0].x + 13 + MeasureText(FilePath.c_str(), 30), rec_SaveGame[0].y + 10, 30, RAYWHITE);
    DrawText(" RESUME ", GetScreenWidth() / 2 - MeasureText(" RESUME ", 30)/2, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" SAVE ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 270, 30, RAYWHITE);
    if (!CanSave){
        DrawText("*WRONG DIRECTORY", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 50, 20, YELLOW);
    }
    EndDrawing();
}
void Menu::LoadGame(){
    ifstream fin;
    fin.open(FilePath + "/gamestate.txt");
    fin >> level >> score >> characterIndex >> TrafficLight >> TrafficLightSecond;
    character[characterIndex].Load(fin);
    GameMap.Load(fin);
    fin.close();
}
void Menu::SaveGame(){
    ofstream fout;
    fout.open(FilePath + "/gamestate.txt");
    fout << level << " " << score << " " << characterIndex << " " << TrafficLight << " " << TrafficLightSecond << '\n';
    character[characterIndex].Save(fout);
    GameMap.Save(fout);
    fout.close();
}