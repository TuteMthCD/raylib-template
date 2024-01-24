#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "ray");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawCircle(GetRenderWidth()/2,GetRenderHeight()/2, 10, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
