#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Overlap.h"

void handleEvent(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void update(sf::Sprite& charizard,sf::Sprite& cookie)
{

	bool eaten;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	     charizard.move(0,-0.05);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		charizard.move(0, 0.05);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		charizard.move(-0.05, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		charizard.move(0.05, 0);

	if (overlap(charizard, cookie))
	{
		eaten++;
		charizard.setScale(1.5, 1.5);
	}
}

void draw(sf::RenderWindow &window,sf::Sprite& charizard,sf::Sprite& cookie)
{
	window.clear();
	window.draw(cookie);
	window.draw(charizard);
	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
	sf::Texture charizardTexture;
	charizardTexture.loadFromFile("Z:\\samplegame\\assets\\charizard.png");

	sf::Sprite charizardSpite(charizardTexture);
	sf::Texture cookieTexture;
	cookieTexture.loadFromFile("C:\\Users\\20224236\\Desktop\\Chocolate_chip_cookies.jpg");
	sf::Sprite cookie(cookieTexture);
	cookie.setPosition(400, 300);

	while (window.isOpen())
	{
		handleEvent(window);
		update(charizardSpite,cookie);
		draw(window, charizardSpite, cookie);
	}

	return 0;
}
