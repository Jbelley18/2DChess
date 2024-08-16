#ifndef Bishop_H
#define Bishop_H

#include "ChessPiece.h"

class Bishop : public ChessPiece {
public:
    Bishop(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // Bishop_H
