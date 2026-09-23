#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Game.h"
#include "Text.h"
#include "GameOver.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int seed = (int)time(nullptr);
    srand(seed);

    // Init window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Apples game!");

    // Game initialization
    ApplesGame::Game game;          
    game.mode = ApplesGame::MODE_50_APPLES | ApplesGame::MODE_FAST | ApplesGame::MODE_FINITY;
    ApplesGame::InitGame(game);       

    // Init game clocks
    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();

    // Main loop
    while (window.isOpen())
    {
        // Calculate time delta
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Read events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                break;
            }
        }

        if (!game.isGameFinished)
        {
            ApplesGame::DrawGame(game, window);
        }
        else
        {
            ApplesGame::DrawGameOverScreen(window);
        }

        ApplesGame::UpdateGame(game, deltaTime);

        window.clear();

        if (!game.isGameFinished)
        {
            ApplesGame::DrawGame(game, window);
        }
        else
        {
            ApplesGame::DrawGameOverScreen(window);
        }

        window.display();
    }

    ApplesGame::DeinializeGame(game);

    
    if (game.apples != nullptr) {
        delete game.apples;
        game.apples = nullptr;
    }


  

    return 0;
}