#include "Game.h"
#include "cassert"
#include <SFML/Audio.hpp>
#include "GameOver.h"
#include "Text.h"

namespace ApplesGame
{
    Text gameoverText;
    bool isInitialized = false;

    void GameOver(Game& game)
    {
        game.deathSound.play();
        game.isGameFinished = true;
        game.timeSinceGameFinish = 0.f;

        AddPlayerToLeaderboard(game, "Player");

        if (!isInitialized)
        {
            InitGOtext(gameoverText);
            isInitialized = true;
        }
    }

    void DrawGameOverScreen(sf::RenderWindow& window)
    {
        if (isInitialized)
        {
            DrawGOtext(gameoverText, window);
        }
    }
}