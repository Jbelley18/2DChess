#include "Square.h"
#include "Board.h"

Square::Square(int x, int y, Color color) : x(x), y(y), color(color) {}

void Square::Draw() {
    DrawRectangle(x, y, Board::squareSize, Board::squareSize, color);
}
