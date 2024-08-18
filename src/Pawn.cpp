#include "Pawn.h"

Pawn::Pawn(Vector2 position, const std::string& texturePath, bool isWhite)
    : ChessPiece(position, texturePath), isWhite(isWhite) {}

std::vector<Vector2> Pawn::GetLegalMoves(const std::vector<ChessPiece*>& pieces) const {
    std::vector<Vector2> legalMoves;
    int direction = isWhite ? -1 : 1;

    // Forward move
    Vector2 forwardPosition = {position.x, position.y + direction * Board::squareSize};
    if (!IsOccupied(forwardPosition, pieces)) {
        legalMoves.push_back(forwardPosition);

        // Double step on initial move
        if ((isWhite && position.y == 6 * Board::squareSize) || (!isWhite && position.y == 1 * Board::squareSize)) {
            Vector2 doubleStepPosition = {position.x, position.y + 2 * direction * Board::squareSize};
            if (!IsOccupied(doubleStepPosition, pieces)) {
                legalMoves.push_back(doubleStepPosition);
            }
        }
    }

    // Capturing moves
    Vector2 captureLeft = {position.x - Board::squareSize, position.y + direction * Board::squareSize};
    Vector2 captureRight = {position.x + Board::squareSize, position.y + direction * Board::squareSize};
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