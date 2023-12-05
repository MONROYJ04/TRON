// Puntuacion.cpp
#include "Puntuacion.hpp"

Puntuacion::Puntuacion()
    : redScore(0), blueScore(0)
{
    // Implementación del constructor
}

void Puntuacion::printScores()
{
    std::cout << "Red:  " << redScore << '\n';
    std::cout << "Blue: " << blueScore << '\n';
}
