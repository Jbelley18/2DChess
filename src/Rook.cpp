#include "Rook.h"

Rook::Rook(Vector2 position, const std::string& texturePath)
    : ChessPiece(position, texturePath) {}

std::vector<Vector2> Rook::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;

    // Rook moves horizontally and vertically
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for (auto& direction : directions) {
        for (int i = 1; i < 8; ++i) {
            Vector2 newPosition = {position.x + direction[0] * i * Board::squareSize, position.y + direction[1] * i * Board::squareSize};
            if (IsOccupied(newPosition, pieces)) {
                if (IsOccupiedByOpponent(newPosition, pieces)) {
                    legalMoves.push_back(newPosition);
                }
                break;
            } else {
                legalMoves.push_back(newPosition);
            }
        }
    }

    return legalMoves;
}

bool Rook::IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool Rook::IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return this->IsOpponent(piece);
        }
    }
    return false;
}