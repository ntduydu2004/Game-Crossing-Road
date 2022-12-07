#include "game.h"
using namespace std;
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 650;
    
    InitWindow(screenWidth, screenHeight, "CROSSING ROAD GAME - CS202 - GROUP 10");  
    bool close = false;
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Game game;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        game.run(close);
        // Draw
        //----------------------------------------------------------------------------------
        // DrawEnterNamePhase(mousePosition, touchPosition, indexMouse, indexTouch, menu, rec_EnterName, background, name, id);
        if (close) break;
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}