#include "Board.h"
#include "Pieces.h"
#include "raylib.h"
#include <iostream>
#include <algorithm>

Board::Board() : selectedPiece(nullptr) {
    for (int row = 0; row < numSquares; row++) {
        for (int col = 0; col < numSquares; col++) {
            Color color = ((row + col) % 2 == 0) ? LIGHTGRAY : DARKGRAY;
            squares.push_back(Square(col * squareSize, row * squareSize, color));
        }
    }
}

void Board::Draw() {
    for (auto& square : squares) {
        square.Draw();  // Draw the board squares
    }

    for (auto& piece : pieces) {
        piece->Draw();  // Draw each piece on the board
    }
}

void Board::InitializePieces() {
    // Initialize white pawns
    pieces.push_back(new Pawn({0, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({150, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({300, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({450, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({600, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({750, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({900, 900}, "assets/images/w_pawn_png_128px.png"));
    pieces.push_back(new Pawn({1050, 900}, "assets/images/w_pawn_png_128px.png"));

    // Initialize black pawns
    pieces.push_back(new Pawn({0, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({150, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({300, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({450, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({600, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({750, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({900, 150}, "assets/images/b_pawn_png_128px.png"));
    pieces.push_back(new Pawn({1050, 150}, "assets/images/b_pawn_png_128px.png"));

    // Initialize white back row (Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook)
    pieces.push_back(new Rook({0, 1050}, "assets/images/w_rook_png_128px.png"));
    pieces.push_back(new Knight({150, 1050}, "assets/images/w_knight_png_128px.png"));
    pieces.push_back(new Bishop({300, 1050}, "assets/images/w_bishop_png_128px.png"));
    pieces.push_back(new Queen({450, 1050}, "assets/images/w_queen_png_128px.png"));
    pieces.push_back(new King({600, 1050}, "assets/images/w_king_png_128px.png"));
    pieces.push_back(new Bishop({750, 1050}, "assets/images/w_bishop_png_128px.png"));
    pieces.push_back(new Knight({900, 1050}, "assets/images/w_knight_png_128px.png"));
    pieces.push_back(new Rook({1050, 1050}, "assets/images/w_rook_png_128px.png"));

    // Initialize black back row (Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook)
    pieces.push_back(new Rook({0, 0}, "assets/images/b_rook_png_128px.png"));
    pieces.push_back(new Knight({150, 0}, "assets/images/b_knight_png_128px.png"));
    pieces.push_back(new Bishop({300, 0}, "assets/images/b_bishop_png_128px.png"));
    pieces.push_back(new Queen({450, 0}, "assets/images/b_queen_png_128px.png"));
    pieces.push_back(new King({600, 0}, "assets/images/b_king_png_128px.png"));
    pieces.push_back(new Bishop({750, 0}, "assets/images/b_bishop_png_128px.png"));
    pieces.push_back(new Knight({900, 0}, "assets/images/b_knight_png_128px.png"));
    pieces.push_back(new Rook({1050, 0}, "assets/images/b_rook_png_128px.png"));
}
bool Board::IsOccupied(Vector2 position) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return true;
        }
    }
    return false;
}

bool Board::IsOccupiedByOpponent(Vector2 position, bool isWhite) const {
    for (const auto& piece : pieces) {
        if (piece->GetPosition().x == position.x && piece->GetPosition().y == position.y) {
            return piece->IsWhite() != isWhite;
        }
    }
    return false;
}

void Board::HandleMouseEvents() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        std::cout << "Mouse left button pressed.\n";
        Vector2 mousePosition = GetMousePosition();
        std::pair<int, int> boardPosition = {static_cast<int>(mousePosition.x / squareSize), static_cast<int>(mousePosition.y / squareSize)};

        std::cout << "Mouse position: (" << mousePosition.x << ", " << mousePosition.y << ")\n";
        std::cout << "Board position: (" << boardPosition.first << ", " << boardPosition.second << ")\n";

        if (selectedPiece) {
            std::cout << "A piece is already selected.\n";
            std::vector<Vector2> legalMoves = selectedPiece->GetLegalMoves(pieces);
            std::cout << "Legal moves calculated:\n";
            std::vector<std::pair<int, int>> legalMovesGrid;
            for (const auto& move : legalMoves) {
                std::pair<int, int> moveGrid = {static_cast<int>(move.x / squareSize), static_cast<int>(move.y / squareSize)};
                legalMovesGrid.push_back(moveGrid);
                std::cout << "Legal move: (" << moveGrid.first << ", " << moveGrid.second << ")\n";
            }
            if (std::find(legalMovesGrid.begin(), legalMovesGrid.end(), boardPosition) != legalMovesGrid.end()) {
                selectedPiece->SetPosition(Vector2{static_cast<float>(boardPosition.first * squareSize), static_cast<float>(boardPosition.second * squareSize)});
                selectedPiece = nullptr;
                std::cout << "Piece moved to: (" << boardPosition.first << ", " << boardPosition.second << ")\n";
            } else {
                selectedPiece = nullptr;
                std::cout << "Invalid move. Piece deselected.\n";
            }
        } else {
            std::cout << "No piece is currently selected.\n";
            std::cout << "Current pieces on the board:\n";
            for (auto& piece : pieces) {
                Vector2 piecePosition = piece->GetPosition();
                std::pair<int, int> pieceBoardPosition = {static_cast<int>(piecePosition.x / squareSize), static_cast<int>(piecePosition.y / squareSize)};
                std::cout << "Piece at: (" << pieceBoardPosition.first << ", " << pieceBoardPosition.second << ")\n";
                if (pieceBoardPosition.first == boardPosition.first && pieceBoardPosition.second == boardPosition.second) {
                    selectedPiece = piece;
                    std::cout << "Piece selected at: (" << boardPosition.first << ", " << boardPosition.second << ")\n";
                    break;
                }
            }
            if (!selectedPiece) {
                std::cout << "No piece found at the clicked position.\n";
            }
        }
    }
}