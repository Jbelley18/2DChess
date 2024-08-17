#include "Board.h"
#include "Pieces.h"
#include "raylib.h"

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

void Board::HandleMouseEvents() {
    Vector2 mousePosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        // Check if a piece is selected
        for (auto& piece : pieces) {
            if (piece->IsMouseOver(mousePosition)) {
                selectedPiece = piece;
                break;
            }
        }
    }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && selectedPiece) {
        // Update the position of the selected piece
        selectedPiece->SetPosition(mousePosition);
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && selectedPiece) {
        // Drop the piece
        selectedPiece = nullptr;
    }
}

