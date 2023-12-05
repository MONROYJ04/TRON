// Ventana.cpp
#include "Ventana.hpp"
#include <Constants.hpp>


Ventana::Ventana(int width, int height, const std::string &title)
    : window(sf::VideoMode(width, height), title)
{
    // Inicialización adicional si es necesaria
}


void Ventana::clear()
{
    window.clear(sf::Color(0, 0, 0));
}

void Ventana::display()
{
    window.display();
}

void Ventana::clearConsole()
{
    system("cls");
}

