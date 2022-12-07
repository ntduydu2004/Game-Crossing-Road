#include "character.h"
using namespace std;
Character::Character(string name, Vector2 PositionChoose){
    moveside = 0;
    movestate = 0;
    this->name = name;
    this->PositionChoose = PositionChoose;
    position = (Vector2){GetScreenWidth()/2 - 65, GetScreenHeight() - 100};
    string Filename = "../data/image/Character/" + name;
    moveState.assign(4, vector <Texture2D> (4));
    // add stand state
    moveState[0][0] = LoadTexture((Filename + "/Up/stand.png").c_str());
    moveState[1][0] = LoadTexture((Filename + "/Right/stand.png").c_str());
    moveState[2][0] = LoadTexture((Filename + "/Down/stand.png").c_str());
    moveState[3][0] = LoadTexture((Filename + "/Left/stand.png").c_str());
    // add move state
    for (int i = 1; i <= 3; i ++){
        moveState[0][i] = LoadTexture((Filename + "/Up/move" + char(i + '0') + ".png").c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[1][i] = LoadTexture((Filename + "/Right/move" + char(i + '0') + ".png").c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[2][i] = LoadTexture((Filename + "/Down/move" + char(i + '0') + ".png").c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[3][i] = LoadTexture((Filename + "/Left/move" + char(i + '0') + ".png").c_str());
    }
}
Character::~Character(){
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            UnloadTexture(moveState[i][j]);
        }
    }
}
void Character::DrawChoose(){
    DrawTextureEx(moveState[2][0], PositionChoose, 0.0f, 2.0f, WHITE);
    DrawText(name.c_str(), PositionChoose.x + 20, PositionChoose.y + 150, 30, YELLOW);
}
void Character::DrawInGame(){
    DrawTextureEx(moveState[moveside][movestate], position, 0.0f, 1.0f, WHITE);
    DrawText(namePlayer.c_str(), position.x + 30 - MeasureText(namePlayer.c_str(), 20)/2, position.y - 20, 20, RAYWHITE);
    // DrawRectangleV(position, (Vector2){30, 30}, WHITE);
}
void Character::ChangeState(short& frames, Map& GameMap){
    movestate = 0;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        if (position.y < GetScreenHeight()/2 - 100){
            position.y < GetScreenHeight()/2 - 100;
            GameMap.Move(5);
        }
        else{
            position.y -= 5;
        }
        if (moveside != 0) frames= 0;
        moveside = 0;
        movestate = (frames/5)%4;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        position.x += 5;
        if (position.x > GetScreenWidth() - 30){
            position.x = GetScreenWidth() - 30;
        }
        if (moveside != 1) frames = 0;
        moveside = 1;
        movestate = (frames/5)%4;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        if (position.y > GetScreenHeight() - 60){
            position.y = GetScreenHeight() - 60;
        }
        position.y += 5;
        if (moveside != 2) frames = 0;
        moveside = 2;
        movestate = (frames/5)%4;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        position.x -= 5;
        if (position.x < -10){
            position.x = -10;
        }
        if (moveside != 3) frames= 0;
        moveside = 3;
        movestate = (frames/5)%4;
    }
    if (position.x < -170) position.x = -170;
    if (position.x > 1010) position.x = 1010;
}
void Character::Move(){
    position.y += 0.5f;
    if (position.y > GetScreenHeight() - 60){
        position.y = GetScreenHeight() - 60;
    }
}