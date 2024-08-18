// main.cpp
#include "raylib.h"
#include "Board.h"

int main() {
    const int screenWidth = Board::squareSize * 8;  // Adjusted window width
    const int screenHeight = Board::squareSize * 8;  // Adjusted window height

    InitWindow(screenWidth, screenHeight, "2D Chess Game");
    InitAudioDevice();  // Initialize audio device
    SetTargetFPS(60);

    Board board;  // Create an instance of the Board class
    board.InitializePieces();  // Initialize pieces on the board

    Sound moveSound = LoadSound("Assets/Audio/move-self.mp3");  // Load the sound file

    while (!WindowShouldClose()) {
        board.HandleMouseEvents();  // Corrected function call

        BeginDrawing();
        ClearBackground(RAYWHITE);

        board.Draw();  // Draw the board

        EndDrawing();
    }

    UnloadSound(moveSound);  // Unload the sound
    CloseAudioDevice();  // Close the audio device
    CloseWindow();

    return 0;
}