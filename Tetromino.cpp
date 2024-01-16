//
// Created by Benny Xu on 2024-01-10.
//

#include "Tetromino.h"
#include <iostream>

Tetromino::Tetromino(Tetromino_type t_type, const int &px, const int &py, const sf::Texture &texture) {
    this->px = px;
    this->py = py;
    this->t_type = t_type;
    single_block.setTexture(texture);

    for (auto i : has_block) {
        i = false;
    }
    switch (t_type) {
        case I:
            has_block[2] = true;
            has_block[6] = true;
            has_block[10] = true;
            has_block[14] = true;
            break;
        case L:
            has_block[1] = true;
            has_block[9] = true;
            has_block[9] = true;
            has_block[10] = true;
            break;
        case J:
            has_block[2] = true;
            has_block[6] = true;
            has_block[9] = true;
            has_block[10] = true;
            break;
        case Z:
            has_block[2] = true;
            has_block[5] = true;
            has_block[6] = true;
            has_block[9] = true;
            break;
        case S:
            has_block[1] = true;
            has_block[5] = true;
            has_block[6] = true;
            has_block[10] = true;
            break;
        case T:
            has_block[2] = true;
            has_block[5] = true;
            has_block[6] = true;
            has_block[10] = true;
            break;
        case O:
            has_block[5] = true;
            has_block[6] = true;
            has_block[9] = true;
            has_block[10] = true;
            break;
    }
}

void Tetromino::rotate() {
    if (t_type == O) {
        return;
    }

    bool temp[16];
    for (int i = 0; i < 16; ++i) {
        temp[i] = has_block[i];
    }
    int width;
    if (t_type == I) {
        width = 4;
    } else {
        width = 3;
    }
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < width; ++y) {
            has_block[y * width + x] = temp[4 * (width - 1) + y - (x * width)];
        }
    }
}

bool Tetromino::check_block(const int &x, const int &y) const {
    if (x < 0 || x >= 4 || y < 0 || y >= 4) {
        std::cout << "coordinates entered are out of range" << std::endl;
        exit(-1);
    }
    return has_block[y * 4 + x];
}

void Tetromino::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (has_block[j * 4 + i]) {
                sf::Sprite temp_block = single_block;
                sf::Vector2f temp_coord(px + float(i) * BLOCK_SIDE_LENGTH,
                                        py + float(j) * BLOCK_SIDE_LENGTH);
                temp_block.setPosition(temp_coord);
                target.draw(single_block, states);
            }
        }
    }
}


Tetromino_type Tetromino::getTType() const {
    return t_type;
}

int Tetromino::getPx() const {
    return px;
}

int Tetromino::getPy() const {
    return py;
}
