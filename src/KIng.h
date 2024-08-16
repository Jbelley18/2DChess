#ifndef King_H
#define King_H

#include "ChessPiece.h"

class King : public ChessPiece {
public:
    King(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // King_H
