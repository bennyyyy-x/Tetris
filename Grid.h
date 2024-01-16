//
// Created by Benny Xu on 2024-01-10.
//

#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#define WIDTH 10
#define HEIGHT 20
#define LEFT_UPPER_CORNER_X 400
#define LEFT_UPPER_CORNER_Y 50

#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include <iostream>
#include <cstdlib>

class Grid : public sf::Drawable {
private:
    const int width = WIDTH, height = HEIGHT;
    int grids[WIDTH][HEIGHT]; // -1 = empty, 0 ~ 6 = Tetromino_type

public:
    Grid();
    void remove_full_row();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void change_grid(const Tetromino &tetromino);
};


#endif //TETRIS_GRID_H
