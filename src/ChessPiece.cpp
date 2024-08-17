#include "ChessPiece.h"

ChessPiece::ChessPiece(Vector2 position, const char* texturePath) : position(position) {
    texture = LoadTexture(texturePath);
}

ChessPiece::~ChessPiece() {
    UnloadTexture(texture);
}

bool ChessPiece::IsMouseOver(Vector2 mousePosition) {
    return (mousePosition.x >= position.x && mousePosition.x <= position.x + texture.width &&
            mousePosition.y >= position.y && mousePosition.y <= position.y + texture.height);
}

void ChessPiece::SetPosition(Vector2 newPosition) {
    position = newPosition;
}