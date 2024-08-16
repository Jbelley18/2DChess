#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class Knight : public ChessPiece {
public:
    Knight(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // ROOK_H
