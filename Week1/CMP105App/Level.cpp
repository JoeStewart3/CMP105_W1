#include "Level.h"
sf::Vector2u pos;
Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circle.setRadius(50);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);
	
	// three color rectangle
	rect1.setSize(sf::Vector2f(50, 50));
	rect1.setPosition(50, 50);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(30, 30));
	rect2.setPosition(60, 60);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(10, 10));
	rect3.setPosition(70, 70);
	rect3.setFillColor(sf::Color::Blue);

	//green rectangle in bottom right
	rect4.setSize(sf::Vector2f(50, 50));
	rect4.setPosition(sf::Vector2f(pos));
	rect4.setFillColor(sf::Color::Green);

	// text
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setPosition(300, 0);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f size = rect4.getSize();
	rect4.setPosition(sf::Vector2f(pos)-size);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(circle);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(text);
	window->draw(rect4);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}