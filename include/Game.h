#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <Vector>
#include "Control.h"
#include "ball.h"
#include "StaticBlock.h"
#include "Hole.h"
#include "HoleContactListener.h"
#include "triangle.h"
#include "door.h"
#include "TextBox.h"

/*! \file Game.h
* \brief Header file for Game Class.
*
*/

/*! \class Game
* \brief Manages the game in runtime.
*
*/
class Game : public sf::Drawable
{
private:
	bool bWin = false;//!<Boolean for if the goal has been reached
	bool bActive = true;//!<Boolean for if the game is active

	sf::View m_view;//!<camera view
	sf::Vector2f m_worldSize = sf::Vector2f(16.0f, 9.0f);//!<size of the world

	b2World* m_pWorld = nullptr;//!<pointer to physics worldspace
	const int mk_iVelocityIterations = 7;//!<How often velocity changes per second
	const int mk_iPositionIterations = 5;//!<How often position changes per second
	const b2Vec2 mk_gravity = b2Vec2(0.0f, 0.0f);//!<Gravirational pull of the world

	int iPar = 5;//!<Value of the par
	int iCurr = 0;//!<Current number of strokes

	Control m_control;//!<Ball Controls
	std::vector<ball> m_ball;//!<Player Ball 
	std::vector<StaticBlock> m_wall;//!<Static Walls
	std::vector<Hole> m_hole;//!<Hole Sensor
	std::vector<triangle> m_triangle;//!<Static triangles
	std::vector<door> m_door;//!<Revolving Doors
	std::vector<TextBox> m_textBox;//!<Text 

	HoleContactListener m_listener;//!<Contact Listener

public:
	//! Constructor
	/*!
	\param window  -  window to draw text to.
	\param orientation - font to be used for text. */
	Game(sf::RenderWindow &window, sf::Font &font);
	
	//! Deconstructor
	~Game();

	//! returns if the mouse is pressed down
	bool isMouseDown();

	//! Runs when the mouse is pressed
	/*!
	\param l_mousePosition - position of the mouse on the screen. */
	void mouseDown(sf::Vector2f l_mousePosition);

	//! Runs when a mouse press stops
	void mouseStop();

	//! Update
	/*!
	\param fTimestep - time taken in last frame. */
	void update(float fTimestep);

	//! Draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//! Draw text 
	void drawText();

	//! Returns a string based on score, used for endscreen
	std::string winString();
};

