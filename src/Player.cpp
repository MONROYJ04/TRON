// Player.cpp
#include <Player.hpp>


   


void Player::Move()
{
    // Implementación del método Move
     sf::RectangleShape &head = body[0];

        int x = head.getPosition().x / blockSize;
        int y = head.getPosition().y / blockSize;

        if (dir.x == 0 && dir.y == -1)
        {
            head.setPosition({x * blockSize, (y - 1) * blockSize});
        }
        if (dir.x == 0 && dir.y == 1)
        {
            head.setPosition({x * blockSize, (y + 1) * blockSize});
        }
        if (dir.x == 1 && dir.y == 0)
        {
            head.setPosition({(x + 1) * blockSize, y * blockSize});
        }
        if (dir.x == -1 && dir.y == 0)
        {
            head.setPosition({(x - 1) * blockSize, y * blockSize});
        }
}

void Player::AddTail()
{
    // Implementación del método AddTail
        sf::RectangleShape newPart;
        newPart.setFillColor(defaultColor);
        newPart.setSize({blockSize, blockSize});

        sf::RectangleShape head = body[0];

        int x = head.getPosition().x;
        int y = head.getPosition().y;

        newPart.setPosition({x, y});

        body.push_back(newPart);
}

void Player::CheckBounds()
{
    // Implementación del método CheckBounds
    sf::RectangleShape &head = body[0];

        int x = head.getPosition().x / blockSize;
        int y = head.getPosition().y / blockSize;

        if (x >= BLOCKS)
            x = 0;
        if (x < 0)
            x = BLOCKS;
        if (y >= BLOCKS)
            y = 0;
        if (y < 0)
            y = BLOCKS;

        x *= blockSize;
        y *= blockSize;

        head.setPosition({x, y});
}

void Player::CheckSelfCollision(int &enemyScore)
{
    // Implementación del método CheckSelfCollision
    for (int i = 1; i < body.size(); ++i)
        {
            int x1 = body[0].getPosition().x;
            int x2 = body[i].getPosition().x;

            int y1 = body[0].getPosition().y;
            int y2 = body[i].getPosition().y;

            if (x1 == x2 && y1 == y2)
            {
                gameOver = true;
                ++enemyScore;
                std::cout << "Press 'R' to go to the next round";
            }
        }
}

void Player::CheckPlayerCollision(Player p, int &enemyScore)
{
    // Implementación del método CheckPlayerCollision
     for (int i = 0; i < p.body.size(); ++i)
        {
            int x1 = body[0].getPosition().x;
            int x2 = p.body[i].getPosition().x;

            int y1 = body[0].getPosition().y;
            int y2 = p.body[i].getPosition().y;

            if (x1 == x2 && y1 == y2)
            {
                gameOver = true;
                ++enemyScore;
                std::cout << "Press 'R' to go to the next round";
            }
        }
}

void Player::ChangeDir(bool useWASD)
{
    // Implementación del método ChangeDir
    if(!useWASD)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir.y!=1)     dir = {0, -1};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir.y!=-1)  dir = {0, 1};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir.x!=1)   dir = {-1, 0};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir.x!=-1) dir = {1, 0};
        }
        else
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir.y!=1)  dir = {0, -1};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir.y!=-1) dir = {0, 1};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir.x!=1)  dir = {-1, 0};
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir.x!=-1) dir = {1, 0};
        }
}

void Player::Draw()
{
    // Implementación del método Draw
    for(int i = 0; i<body.size(); ++i)
            window.draw(body[i]);
}

void Player::Update(Player enemy, int &enemyScore)
{
    // Implementación del método Update
      Move();
        CheckSelfCollision(enemyScore);
        CheckPlayerCollision(enemy, enemyScore);
        AddTail();
        CheckBounds();
}

Player::Player(sf::Color Color, sf::Vector2f Position)
{
    // Implementación del constructor
    sf::RectangleShape head;

        defaultColor = Color;
        head.setFillColor(Color);
        head.setSize({blockSize, blockSize});
        head.setPosition(Position);
        body.push_back(head);
}
