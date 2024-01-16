#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Tetromino.h"
#include "Grid.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900

int main() {
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

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris");


    while (window.isOpen()) {
        window.clear();
        sf::Texture background_texture;
        if (!background_texture.loadFromFile("../TetrisAssets/Background.png")) {
            std::cout << "Could not load background texture" << std::endl;
            exit(-1);
        }
        sf::Sprite background(background_texture);
        background.setScale(float(WINDOW_WIDTH) / 1920,
                            float(WINDOW_WIDTH) / 1080);
        window.draw(background);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Grid g;
        window.draw(g);
        window.display();

    }
}