#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
public:
    Rook(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // ROOK_H
