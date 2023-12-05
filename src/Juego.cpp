// Juego.cpp
#include <Juego.hpp>
#include <Player.hpp>
#include <Ventana.hpp>    // Add missing include for Ventana
#include <Puntuacion.hpp> // Add missing include for Puntuacion

Juego::Juego()
    : p1(sf::Color::Red, sf::Vector2f(WIDTH / 4, HEIGHT / 2)),
      p2(sf::Color::Blue, sf::Vector2f(WIDTH / 4, HEIGHT / 2)),
    : ventana(new Ventana(WIDTH, HEIGHT, "TRON"))
{
    // Inicialización adicional si es necesaria

    // Por ejemplo, si quieres configurar alguna característica específica del juego
    // o inicializar variables adicionales, lo puedes hacer aquí.
}

void Juego::run()
{
    // Implementación del método run
    sf::Clock clock;
    float t = 0;
    int blueScore = 0; // Add declaration for blueScore
    int redScore = 0;  // Add declaration for redScore

    while (ventana->window.isOpen())
    {
        // Lógica del juego
        sf::Event e;
        while (ventana->window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                ventana->window.close();
            if (gameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                run();
        }

        // Resto del bucle principal del juego
        sf::Time time = clock.restart();
        t += time.asSeconds();

        if (!gameOver)
        {
            p1->ChangeDir(true);
            p2->ChangeDir(false);
            if (t > 0.03)
            {
                t = 0;
                p1->Update(*p2, blueScore);
                p2->Update(*p1, redScore);
            }
        }

        ventana->clear();
        p1->Draw();
        p2->Draw();
        ventana->display();
    }
}
