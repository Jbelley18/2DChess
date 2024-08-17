// main.cpp
#include "raylib.h"
#include "Board.h"

int main() {
    const int screenWidth = Board::squareSize * 8;  // Adjusted window width
    const int screenHeight = Board::squareSize * 8;  // Adjusted window height

    InitWindow(screenWidth, screenHeight, "2D Chess Game");
    SetTargetFPS(60);

    Board board;  // Create an instance of the Board class
    board.InitializePieces();  // Initialize pieces on the board

    while (!WindowShouldClose()) {
        board.HandleMouseEvents();  // Handle mouse events

        BeginDrawing();
        ClearBackground(RAYWHITE);

        board.Draw();  // Draw the board

        EndDrawing();
    }

    CloseWindow();

    return 0;
}