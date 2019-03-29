/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game.h"

void main() /** Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Golf"); // Open main window

	sf::Font l_font;//!< load font
	bool bSuccess = l_font.loadFromFile(".\\assets\\fonts\\VT323.TTF");//Loads font from file
	if (!bSuccess) {
		std::cout << "ERROR - VT323.TTF not found" << std::endl;
	}

	Game game(window, l_font);

	float fFrameTime = 1.f / 60.f;

	// Start a clock to provide time for the physics
	sf::Clock clock;

	// Run a game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);//!< get mouse position
				sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);//!< convert to view position from screen position
				game.mouseDown(worldPos);
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				game.mouseStop();
			}
		}
		if (game.isMouseDown()) {//!< if mouse is down send mouse position to game
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);//!< get mouse position
			sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);//!< convert to view position from screen position
			game.mouseDown(worldPos);
		}

		//! Find out how much time has elapsed
		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		//! If a frame has past the update the game object
		if (m_fElapsedTime > fFrameTime)
		{
			game.update(m_fElapsedTime);
			clock.restart();
		}

		//! clear window
		window.clear(sf::Color(70,162,59));
		//! draw game
		window.draw(game);
		//! draw text
		game.drawText();
		//! show window
		window.display();
	}



}