#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
#include <vector>
#include <map.h>
#include <string.h>
#include "menu.h"
#include "raygui.h"
class Game: public Menu{
private:
    
public:
    Game(){};
    ~Game(){};
    void run(bool& close);
    void SaveScore();
    void LoadScore();
};