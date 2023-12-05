// Ventana.hpp
#pragma once

#include <SFML/Graphics.hpp>


class Ventana
{
public:
    sf::RenderWindow window;

    void clear();
    void display();
    void clearConsole();

    Ventana(int width, int height, const std::string &title);
    
};
