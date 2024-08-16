#include "Queen.h"
#include "Board.h" 

Queen::Queen(Vector2 position, const char* texturePath)
    : ChessPiece(position, texturePath) {}

void Queen::Draw() {
    float scale = 1.0f;  // No scaling needed if using 128px textures in 150px squares
    Vector2 adjustedPosition = { 
        position.x + (Board::squareSize - texture.width * scale) / 2,
        position.y + (Board::squareSize - texture.height * scale) / 2 
    };
    DrawTextureEx(texture, adjustedPosition, 0.0f, scale, WHITE);  // Draw the Queen texture
}
