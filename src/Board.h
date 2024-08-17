#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <vector>
#include "Pawn.h"  // Include this if you need to work with pieces in the Board class

class Board {
public:
    static const int squareSize = 150;  // Updated square size
    static const int numSquares = 8;

    Board();  // Constructor
    void Draw();  // Draw the board
    void InitializePieces();  // Initialize pieces
    void HandleMouseEvents();  // Handle mouse events

private:
    std::vector<Square> squares;  // Vector to store squares
    std::vector<ChessPiece*> pieces;  // Vector to store pieces
    ChessPiece* selectedPiece;  // Track the selected piece
};


#endif // BOARD_H
