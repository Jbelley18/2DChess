#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "raylib.h"
#include <string>
#include <vector>

class ChessPiece {
public:
    ChessPiece(Vector2 position, const std::string& texturePath);
    virtual ~ChessPiece();
    virtual void Draw() const;
    virtual std::vector<Vector2> GetLegalMoves(const std::vector<ChessPiece*>& pieces) const = 0;
    Vector2 GetPosition() const;
    void SetPosition(Vector2 newPosition);
    bool IsWhite() const;
    bool IsOpponent(const ChessPiece* other) const;  // Add this method

protected:
    Vector2 position;
    Texture2D texture;
    bool isWhite;
    Color color;
};

#endif // CHESSPIECE_H