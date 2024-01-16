//
// Created by Benny Xu on 2024-01-10.
//

#include "Grid.h"
#include "Tetromino.h"

Grid::Grid() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
//            grids[i][j] = -1;
            grids[i][j] = rand() % 8 - 1; // Random Test
        }
    }
}

void Grid::remove_full_row() {
    for (int y = 0; y < height; ++y) {
        bool is_full = true;
        for (int x = 0; x < width; ++x) {
            if (!grids[x][y]) {
                is_full = false;
                break;
            }
        }
        if (is_full) {
            for (int prev_y = y; prev_y > 0; --prev_y) {
                for (int x = 0; x < width; ++x) {
                    grids[x][prev_y] = grids[x][prev_y - 1];
                    if (prev_y == 1) {
                        grids[x][0] = -1;
                    }
                }
            }
        }
    }
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    std::string Colors[8] = {"Cyan",
                             "Orange",
                             "Blue",
                             "Red",
                             "Green",
                             "Purple",
                             "Yellow",
                             "Empty"};
    std::string Filenames[8];
    sf::Texture textures[8];
    for (int i = 0; i < 8; ++i) {
        Filenames[i] = "../TetrisAssets/Tile" + Colors[i] + ".png";
        if (!textures[i].loadFromFile(Filenames[i])) {
            std::cout << "Could not load texture from image" << std::endl;
            exit(-1);
        }
    }

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            sf::Sprite block;
            if (grids[x][y] == -1) {
                block.setTexture(textures[7]);
            } else {
                block.setTexture(textures[grids[x][y]]);
            }
            block.setScale(float(BLOCK_SIDE_LENGTH) / 256, float(BLOCK_SIDE_LENGTH) / 256);
            block.setPosition(LEFT_UPPER_CORNER_X + float(x) * BLOCK_SIDE_LENGTH,
                              LEFT_UPPER_CORNER_Y + float(y) * BLOCK_SIDE_LENGTH);
            target.draw(block);
        }
    }
}

void Grid::change_grid(const Tetromino &tetromino) {
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if (tetromino.check_block(x, y)) {
                grids[tetromino.getPx() + x][tetromino.getPy() + y] = tetromino.getTType();
            }
        }
    }
}