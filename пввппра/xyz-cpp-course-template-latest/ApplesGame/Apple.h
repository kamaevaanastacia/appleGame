#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"
#include <SFML/Audio.hpp>

namespace ApplesGame
{
	struct Apple
	{
		Position2D position;
		sf::Sprite sprite; 
		bool isEaten;
	};

	struct Game;

	void InitApple(Apple& apple, const Game& game);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
}