#include <stdio.h>
#include <raylib.h>

int main (void) {
    constexpr auto screen_width = 800;
    constexpr auto screen_height = 600;

    InitWindow(screen_width, screen_height, "Hello raylib master and C23");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(100, 100, 100, 200, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}