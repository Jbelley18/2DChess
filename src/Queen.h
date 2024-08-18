#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"
#include "Board.h"
#include <vector>

class Queen : public ChessPiece {
public:
    Queen(Vector2 position, const std::string& texturePath);
    std::vector<Vector2> GetLegalMoves(const std::vector<ChessPiece*>& pieces) const override;

private:
    bool IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
    bool IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const;
};

#endif // QUEEN_H