#include "Queen.h"

Queen::Queen(Vector2 position, const std::string& texturePath)
    : ChessPiece(position, texturePath) {}

std::vector<Vector2> Queen::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;

    // Horizontal, vertical, and diagonal moves
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };
    for (auto& direction : directions) {
        Vector2 move = position;
        while (true) {
            move.x += direction[0] * Board::squareSize;
            move.y += direction[1] * Board::squareSize;
            if (IsOccupied(move, pieces)) {
                if (IsOccupiedByOpponent(move, pieces)) {
                    legalMoves.push_back(move);
                }
                break;
            }
            legalMoves.push_back(move);
        }
    }

    return legalMoves;
}

bool Queen::IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool Queen::IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return this->IsOpponent(piece);
        }
    }
    return false;
}