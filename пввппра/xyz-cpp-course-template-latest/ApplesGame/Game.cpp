#include "Game.h"
#include "cassert"
#include "Apple.h"
#include "Player.h"
#include "Rock.h"
#include <SFML/Audio.hpp>
#include "GameOver.h"
#include "Text.h"

namespace ApplesGame
{

	void ClearApples(Game& game)
	{
		if (game.apples != nullptr)
		{
			delete[] game.apples;
			game.apples = nullptr;
			game.appleCount = 0;
		}
	}

	void RestartGame(Game& game)
	{
		InitPlayer(game.player, game);

		game.player.speed = game.normalSpeed;

		// Init apples
		for (int i = 0; i < game.appleCount; ++i)
		{
			InitApple(game.apples[i], game);
		}

		// Init rocks
		for (int i = 0; i < NUM_ROCKS; ++i)
		{
			InitRock(game.rocks[i], game);
		}

		game.numEatenApples = 0;
		game.isGameFinished = false;
		game.timeSinceGameFinish = 0;

		game.eatSound.setBuffer(game.eatBuffer);
		game.eatSound.setVolume(40.f);
		game.deathSound.setBuffer(game.deathBuffer);
		game.deathSound.setVolume(30.f);
	}

	void InitGame(Game& game)
	{
		assert(game.playerTexure.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.rockTexure.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.appleTexure.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.eatBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		assert(game.deathBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));
	
		ClearApples(game);
		// режимы
		game.appleCount = (game.mode & MODE_50_APPLES) ? 50 : 20;
		game.apples = new Apple[game.appleCount];

		if (game.mode & MODE_FAST) {
			game.normalSpeed = INITIAL_SPEED;
		}
		else {
			game.normalSpeed = INITIAL_SPEED;
		}
		


		game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.f, 0.f);

		RestartGame(game);
	}

	void UpdateGame(Game& game, float deltaTime)
	{
		// Update game state
		if (!game.isGameFinished)
		{
			// Handle input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				game.player.direction = PlayerDirection::Right;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				game.player.direction = PlayerDirection::Up;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				game.player.direction = PlayerDirection::Left;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				game.player.direction = PlayerDirection::Down;
			}

			// Update player state
			switch (game.player.direction)
			{
			case PlayerDirection::Right:
			{
				game.player.position.x += game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Up:
			{
				game.player.position.y -= game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Left:
			{
				game.player.position.x -= game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Down:
			{
				game.player.position.y += game.player.speed * deltaTime;
				break;
			}
			}

			// Find player collisions with apples
			for (int i = 0; i < game.appleCount; ++i)
			{
				// ≈сли €блоко уже съедено Ч пропускаем
				if (game.apples[i].isEaten)
					continue;

				if (IsCirclesCollide(game.player.position, PLAYER_SIZE / 2.f,
					game.apples[i].position, APPLE_SIZE / 2.f))
				{
					game.eatSound.play();
					++game.numEatenApples;
					game.player.speed += ACCELERATION;

					if (game.mode & MODE_FAST) {
						game.player.speed += ACCELERATION;
					}
					else {
						game.player.speed = INITIAL_SPEED;
					}

					if (game.mode & MODE_FINITY)
					{
						game.apples[i].isEaten = true;
					}
					else
					{
						Position2D newPos = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
						game.apples[i].position.x = newPos.x;
						game.apples[i].position.y = newPos.y;
					}
					if (game.numEatenApples >= game.appleCount)
					{
						game.isGameFinished = true;
						break;
					}
				}
			}

			// Find player collisions with rocks
			for (int i = 0; i < NUM_ROCKS; ++i)
			{
				if (IsRectanglesCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE },
					game.rocks[i].position, { ROCK_SIZE, ROCK_SIZE }))
				{
					GameOver(game);
				}
			}

			// Check screen borders collision
			if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f || game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
				game.player.position.y - PLAYER_SIZE / 2.f < 0.f || game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
			{
				GameOver(game);
			}
		}
		else
		{
			if (game.timeSinceGameFinish <= PAUSE_LENGTH)
			{
				game.timeSinceGameFinish += deltaTime;
				game.background.setFillColor(sf::Color::Red);
			}
			else
			{
				// Reset backgound
				game.background.setFillColor(sf::Color::Black);

				RestartGame(game);
			}
		}
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.background);
		
		DrawPlayer(game.player, window);

		for (int i = 0; i < game.appleCount; ++i)
		{
			if (!game.apples[i].isEaten)
			{
				DrawApple(game.apples[i], window);
			}
		}

		for (int i = 0; i < NUM_ROCKS; ++i)
		{
			DrawRock(game.rocks[i], window);
		}

	}

	void DeinializeGame(Game& game)
	{
		ClearApples(game);
	}
}

