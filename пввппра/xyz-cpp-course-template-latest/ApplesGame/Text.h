#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	struct Text
	{
		sf::Font font;
		sf::Text textObj;
	};
		void InitGOtext(Text& text);
		void DrawGOtext(const Text& text, sf::RenderWindow& window);
}
