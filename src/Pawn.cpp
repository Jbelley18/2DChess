#include "Pawn.h"
#include "Board.h"

// If the Board class is within a namespace, ensure consistency
// Assuming it's not, you can omit the namespace part

Pawn::Pawn(Vector2 position, const char* texturePath)
    : ChessPiece(position, texturePath) {}

void Pawn::Draw() {
    float scale = 1.0f;  // No longer a need to scale since the piece fits within the square
    Vector2 adjustedPosition = { 
        position.x + (Board::squareSize - texture.width * scale) / 2,
        position.y + (Board::squareSize - texture.height * scale) / 2 
    };
    DrawTextureEx(texture, adjustedPosition, 0.0f, scale, WHITE);  // Draw without scaling
}