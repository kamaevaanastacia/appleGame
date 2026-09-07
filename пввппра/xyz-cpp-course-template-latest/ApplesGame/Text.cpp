#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Constants.h"
#include "cassert"
#include "Game.h"


namespace ApplesGame
{

    void InitGOtext(Text& text)
    {    
        assert(text.font.loadFromFile(RESOURCES_PATH2 + "\\Roboto-Medium.ttf"));
        
        text.textObj.setFont(text.font);
        text.textObj.setString("Game Over");
        text.textObj.setCharacterSize(48);
        text.textObj.setFillColor(sf::Color::White); 
        text.textObj.setPosition(300.f, 250.f);
    }

    void DrawGOtext(const Text& text, sf::RenderWindow& window)
    {
        window.draw(text.textObj);
    }
}