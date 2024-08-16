#ifndef Queen_H
#define Queen_H

#include "ChessPiece.h"

class Queen : public ChessPiece {
public:
    Queen(Vector2 position, const char* texturePath);
    void Draw() override;
};

#endif // Queen_H
