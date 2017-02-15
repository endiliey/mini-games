#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "First SFML!");

	// create a texture and sprite
	sf::Texture endiTexture;
	endiTexture.loadFromFile("endi.png");
	
	sf::Sprite endi(endiTexture);
	sf::Vector2u size = endiTexture.getSize();
	endi.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);
		
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		if((endi.getPosition().x + (size.x / 2) > window.getSize().x 
		    && increment.x > 0) || (endi.getPosition().x - (size.x / 2) < 0 
                    && increment.x < 0))
		{
			// Reverse direction on X axis
			increment.x = -increment.x;
		}

		if((endi.getPosition().y + (size.y / 2) > window.getSize().y 
		    && increment.y > 0) || (endi.getPosition().y - (size.y / 2) < 0 
		    && increment.y < 0))
		{
			// Reverse direction on Y axis
			increment.y = -increment.y;
		}
		
		// move randomly with some increment	
		endi.setPosition(endi.getPosition() + increment);

		window.clear(sf::Color::White);
		window.draw(endi);
		window.display();
	}
}
