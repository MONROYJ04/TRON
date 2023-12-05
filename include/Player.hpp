// Player.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
public:

    std::vector<sf::RectangleShape> body;

    sf::Color defaultColor;
    sf::Vector2f dir = {0, -1};

    void Move();
    void AddTail();
    void CheckBounds();
    void CheckSelfCollision(int &enemyScore);
    void CheckPlayerCollision(Player p, int &enemyScore);
    void ChangeDir(bool useWASD);
    void Draw();
    void Update(Player enemy, int &enemyScore);

    Player(const sf::Color& color, const sf::Vector2f& position);
};
