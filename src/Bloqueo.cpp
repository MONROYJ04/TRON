// Bloqueo.cpp
#include <Bloqueo.hpp>


Bloqueo::Bloqueo(const sf::Vector2f& position, const sf::Color& color)
    : color(color)
{
    shape.setSize(sf::Vector2f(10.f, 10.f)); // Tamaño del bloque, ajusta según tu necesidad
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Bloqueo::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}