#include "ChessPiece.h"
#include "raylib.h"

ChessPiece::ChessPiece(Vector2 position, const std::string& texturePath)
    : position(position), isWhite(texturePath.find("w_") != std::string::npos) {
    texture = LoadTexture(texturePath.c_str());
}

ChessPiece::~ChessPiece() {
    UnloadTexture(texture);
}

void ChessPiece::Draw() const {
    DrawTexture(texture, position.x, position.y, WHITE);
}

Vector2 ChessPiece::GetPosition() const {
    return position;
}

void ChessPiece::SetPosition(Vector2 newPosition) {
    position = newPosition;
}

bool ChessPiece::IsWhite() const {
    return isWhite;
}

bool ChessPiece::IsOpponent(const ChessPiece* other) const {
    return this->IsWhite() != other->IsWhite();
}
bool Vector2Equals(Vector2 v1, Vector2 v2) {
    return (v1.x == v2.x) && (v1.y == v2.y);
}