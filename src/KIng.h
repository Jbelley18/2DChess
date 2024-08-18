#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
#include "Board.h"
#include <vector>

class King : public ChessPiece {
public:
    King(Vector2 position, const std::string& texturePath);
    std::vector<Vector2> GetLegalMoves(const std::vector<ChessPiece*>& pieces) const override;

private:
    bool IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
    bool IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
};

#endif // KING_H