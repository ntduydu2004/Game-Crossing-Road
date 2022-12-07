#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
#include "map.h"
using namespace std;
class Character{
private:
    vector <vector <Texture2D>> moveState;
    string name;
    Vector2 PositionChoose;
public:
    short moveside; // 0: up, 1: right, 2: down, 3: left
    short movestate;
    Vector2 position;
    string namePlayer;
    Character(string name, Vector2 PositionChoose);
    ~Character();
    void Move();
    void DrawInGame();
    void DrawChoose();
    void ChangeState(short& frames, Map& GameMap);
};