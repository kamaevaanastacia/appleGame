#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>

struct Game;

namespace ApplesGame

{
        void GameOver(Game& game);
        void DrawGameOverScreen(sf::RenderWindow& window);
}
