#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include "Board.h"
#include <vector>

class Pawn : public ChessPiece {
public:
    Pawn(Vector2 position, const std::string& texturePath);
    std::vector<Vector2> GetLegalMoves(const std::vector<ChessPiece*>& pieces) const override;

private:
    bool IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
    bool IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
};

#endif // PAWN_H