#include "Knight.h"

Knight::Knight(Vector2 position, const std::string& texturePath)
    : ChessPiece(position, texturePath) {}

std::vector<Vector2> Knight::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;

    // Knight moves
    int moves[8][2] = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    };

    for (auto& move : moves) {
        Vector2 newPosition = {position.x + move[0] * Board::squareSize, position.y + move[1] * Board::squareSize};
        if (!IsOccupied(newPosition, pieces) || IsOccupiedByOpponent(newPosition, pieces)) {
            legalMoves.push_back(newPosition);
        }
    }

    return legalMoves;
}

bool Knight::IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool Knight::IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return this->IsOpponent(piece);
        }
    }
    return false;
}