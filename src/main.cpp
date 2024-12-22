#include "raylib.h"
#include <cstdio>
#include <iostream>

using namespace std;

Color blue = {0, 0, 255, 255};
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

class Food
{
public:
    Vector2 position;
    Texture2D texture;
    Image image;

    Food()
    {
        image = LoadImage("../Graphics/Santa_Hat.png");
        texture = LoadTextureFromImage(image);
        position = GenerateRandomPos();
    }

    ~Food()
    {
        UnloadTexture(texture);
        UnloadImage(image);
    }

    void Draw()
    {
        // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);

        return Vector2{x, y};
    }
};

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Christmas Snake");
    SetTargetFPS(60);

    Food food = Food();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Drawing
        ClearBackground(green);
        food.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}