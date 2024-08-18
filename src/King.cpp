#include "King.h"

King::King(Vector2 position, const std::string& texturePath)
    : ChessPiece(position, texturePath) {}

std::vector<Vector2> King::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;

    // King moves
    int moves[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    for (auto& move : moves) {
        Vector2 newPosition = {position.x + move[0] * Board::squareSize, position.y + move[1] * Board::squareSize};
        if (!IsOccupied(newPosition, pieces) || IsOccupiedByOpponent(newPosition, pieces)) {
            legalMoves.push_back(newPosition);
        }
    }

    return legalMoves;
}

bool King::IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool King::IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return this->IsOpponent(piece);
        }
    }
    return false;
}