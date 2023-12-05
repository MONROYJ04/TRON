// Bloqueo.hpp
#pragma once
#include <SFML/Graphics.hpp>


class Bloqueo
{

private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
    float size;

public:
     Bloqueo(const sf::Vector2f& position, const sf::Color& color);
    void draw(sf::RenderWindow& window) const;     
    
};
