//
// Created by Benny Xu on 2024-01-10.
//

#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

#include <SFML/Graphics.hpp>

#define BLOCK_SIDE_LENGTH 40

enum Tetromino_type {I, L, J, Z, S, T, O};

class Tetromino : public sf::Drawable {
private:
    Tetromino_type t_type;
    bool has_block[16];
    int px, py;
    sf::Sprite single_block;

public:
    Tetromino(Tetromino_type t_type, const int &px, const int &py, const sf::Texture &texture);
    void rotate();
    bool check_block(const int &x, const int &y) const;

    int getPx() const;
    Tetromino_type getTType() const;
    int getPy() const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //TETRIS_TETROMINO_H
