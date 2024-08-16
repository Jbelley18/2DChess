#ifndef SQUARE_H
#define SQUARE_H

#include "raylib.h"

class Square {
public:
    Square(int x, int y, Color color);

    void Draw();  // Draw the square

private:
    int x, y;  // Position of the square
    Color color;  // Color of the square
};

#endif // SQUARE_H
