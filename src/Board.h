#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Square.h"
#include "ChessPiece.h"
#include "raylib.h"

class Board {
public:
    Board();
    void Draw();
    void InitializePieces();
    bool IsOccupied(Vector2 position) const;
    bool IsOccupiedByOpponent(Vector2 position, bool isWhite) const;
    void HandleMouseEvents();

    static const int squareSize = 150;  // Define the square size

private:
    std::vector<Square> squares;
    std::vector<ChessPiece*> pieces;
    ChessPiece* selectedPiece;
    static const int numSquares = 8;  // Assuming an 8x8 board
};

#endif // BOARD_H