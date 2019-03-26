/*******************************************************************************************
*
*   raylib [core] example - 2d camera
*
*   This example has been created using raylib 1.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "stdint.h"
#include "stdbool.h"

#include "raylib.h"

#define FIELD_WIDTH 500
#define FIELD_HEIGHT 700

typedef struct stone
{
    uint16_t player;
    Vector2 pos;
    float rotation;
    float v;
    float rv;
} stone;


enum actions { left, right, up, down, interact, };

//enum tile_types { player, enemy, unoccupied, prohibited, };

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Super Curling");
    
    //Rectangle player = { 400, 280, 40, 40 };
    //Rectangle tiles[GRID_HEIGHT][GRID_WIDTH];
    //Color tileColors[GRID_HEIGHT][GRID_WIDTH];
    Rectangle field;
    field.width = FIELD_WIDTH;
    field.height = FIELD_HEIGHT;
    field.x = 100;
    field.y = 100;
    Color field_color = (Color){50, 50, 50, 255};

    int32_t player_x = 2;
    int32_t player_y = 2;
    
    Color player1_color = (Color){100, 100, 100, 255 };
    Color player2_color = (Color){200, 200, 200, 255 };
    

    //tile_types grid[GRID_HEIGHT][GRID_WIDTH];

    Camera2D camera;
    
    camera.target = (Vector2){ player_x + 20, player_y + 20 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT))
        {
            player_x += 1;              // Player movement
            //camera.offset.x -= 2;       // Camera displacement with player movement
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            player_x -= 1;              // Player movement
            //camera.offset.x += 2;       // Camera displacement with player movement
        }
        
        // Camera target follows player
        camera.target = (Vector2){ player_x + 20, player_y + 20 };
        
        // Camera rotation controls
        if (IsKeyDown(KEY_A)) camera.rotation--;
        else if (IsKeyDown(KEY_S)) camera.rotation++;
        
        // Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) camera.rotation = 40;         
        else if (camera.rotation < -40) camera.rotation = -40;
        
        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        
        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        
        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R)) 
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
        
            BeginMode2D(camera);

                DrawRectangleRec(field, field_color);


                //DrawRectangle(player_x*(TILE_WIDTH+spacing)+spacing,
                //        player_y*(TILE_HEIGHT+spacing)+spacing,
                //        TILE_WIDTH, TILE_HEIGHT, RED);
                
                //for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i]);
                
                //DrawRectangleRec(player, RED);
                
                //DrawLine(camera.target.x, -screenHeight*10, camera.target.x, screenHeight*10, GREEN);
                //DrawLine(-screenWidth*10, camera.target.y, screenWidth*10, camera.target.y, GREEN);
                
            EndMode2D();
            
            DrawText("SCREEN AREA", 640, 10, 20, RED);
            
            DrawRectangle(0, 0, screenWidth, 5, RED);
            DrawRectangle(0, 5, 5, screenHeight - 10, RED);
            DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
            DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);
            
            DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 250, 113, BLUE);
            
            DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
            DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
            DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
            DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
