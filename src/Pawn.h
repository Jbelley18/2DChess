#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // PAWN_H
