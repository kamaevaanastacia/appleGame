#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include <SFML/Audio.hpp>

namespace ApplesGame
{
	struct Game
	{
		Player player;
		Apple* apples = nullptr;
		int mode = 0; // маска
		int appleCount = 0;
		Rock rocks[NUM_ROCKS];
		float normalSpeed;

		// Global game data
		int numEatenApples = 0;
		bool isGameFinished = false;
		float timeSinceGameFinish = 0.f;
		sf::RectangleShape background;

		//Resources
		sf::Sound eatSound;
		sf::SoundBuffer eatBuffer;
		sf::Sound deathSound;
		sf::SoundBuffer deathBuffer;
		sf::Texture playerTexure;
		sf::Texture rockTexure;
		sf::Texture appleTexure;
	};

	void RestartGame(Game& game);
	void InitGame(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void DeinializeGame(Game& game);
}