#include "Apple.h"
#include "Game.h"

namespace ApplesGame
{
	void InitApple(Apple& apple, const Game& game)
	{
		auto pos = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
		apple.position.x = pos.x;
		apple.position.y = pos.y;

		// Init apple sprite גלוסעמ shape
		apple.sprite.setTexture(game.appleTexure);
		SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);

		apple.isEaten = false;
	
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}
}