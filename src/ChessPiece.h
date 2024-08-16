#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "raylib.h"

class ChessPiece {
public:
    ChessPiece(Vector2 position, const char* texturePath);
    virtual ~ChessPiece();

    virtual void Draw() = 0;  // Pure virtual function

protected:
    Vector2 position;
    Texture2D texture;  // Texture for the piece
};

#endif // CHESSPIECE_H
