#include "Player.h"
#include "Game.h"

namespace ApplesGame
{
	void InitPlayer(Player& player, const Game& game)
	{
		// Init player state
		player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = PlayerDirection::Right;

		// Init player sprite גלוסעמ shape
		player.sprite.setTexture(game.playerTexure);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
		player.sprite.setRotation(0.f);
	}

	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.position.x, player.position.y);
		
		//sprite direction
		if (player.direction == PlayerDirection::Left)
		{
			player.sprite.setRotation(180.f);
		}
		else if (player.direction == PlayerDirection::Right)
		{
			player.sprite.setRotation(0.f);
		}
		else if (player.direction == PlayerDirection::Up)
		{
			player.sprite.setRotation(-90.f);
		}
		else if (player.direction == PlayerDirection::Down)
		{
			player.sprite.setRotation(90.f);
		}

		window.draw(player.sprite);
	}
}