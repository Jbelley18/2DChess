#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Vector2 position, const std::string& texturePath)
    : ChessPiece(position, texturePath) {}

std::vector<Vector2> Pawn::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;

    // Example logic for pawn moves (assuming white pawn moving up)
    Vector2 forwardMove = {position.x, position.y - Board::squareSize};
    if (!IsOccupied(forwardMove, pieces)) {
        legalMoves.push_back(forwardMove);

        // Initial double move
        if (position.y == 6 * Board::squareSize) {  // Assuming the pawn starts at y = 6 * squareSize
            Vector2 doubleMove = {position.x, position.y - 2 * Board::squareSize};
            if (!IsOccupied(doubleMove, pieces)) {
                legalMoves.push_back(doubleMove);
            }
        }
    }

    // Capturing moves
    Vector2 captureLeft = {position.x - Board::squareSize, position.y - Board::squareSize};
    Vector2 captureRight = {position.x + Board::squareSize, position.y - Board::squareSize};
    if (IsOccupiedByOpponent(captureLeft, pieces)) {
        legalMoves.push_back(captureLeft);
    }
    if (IsOccupiedByOpponent(captureRight, pieces)) {
        legalMoves.push_back(captureRight);
    }

    return legalMoves;
}

bool Pawn::IsOccupied(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool Pawn::IsOccupiedByOpponent(Vector2 position, const std::vector<ChessPiece*>& pieces) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return this->IsOpponent(piece);
        }
    }
    return false;
}