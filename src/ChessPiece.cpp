#include "ChessPiece.h"

ChessPiece::ChessPiece(Vector2 position, const char* texturePath)
    : position(position) {
    texture = LoadTexture(texturePath);  // Load the texture from the given path
}

ChessPiece::~ChessPiece() {
    UnloadTexture(texture);  // Unload the texture when the piece is destroyed
}
