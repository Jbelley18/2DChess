#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"
#include "Board.h"
#include <vector>

class Rook : public ChessPiece {
public:
    Rook(Vector2 position, const std::string& texturePath);
    std::vector<Vector2> GetLegalMoves(const std::vector<ChessPiece*>& pieces) const override;

private:
    bool IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
    bool IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
};

#endif // ROOK_H