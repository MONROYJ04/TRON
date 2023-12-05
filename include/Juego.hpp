// Juego.hpp
#pragma once

#include <SFML/Graphics.hpp> // Add missing import

class Player; // Forward declaration
class Ventana; // Forward declaration
class Control; // Forward declaration
class Puntuacion; // Forward declaration

class Juego
{

public:
    void run();
    Juego();

private:
    const int BLOCKS = 90;
    const int blockSize = 7;
    const int WIDTH = BLOCKS * blockSize;
    const int HEIGHT = BLOCKS * blockSize;

    sf::RenderWindow window;
    bool gameOver = false;

    Player* p1; // Change to pointer
    Player* p2; // Change to pointer

    Ventana* ventana; // Change to pointer
    Control* control; // Change to pointer
    Puntuacion* puntuacion; // Change to pointer
};
