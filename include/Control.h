#pragma once
#include <SFML/Graphics.hpp>

/*! \file Control.h
* \brief Header file for Control Class.
*
*/

/*! \class Control
* \brief Used by the player to control the balls direction and speed.
*
*/
class Control : public sf::Drawable
{
private:
	sf::RectangleShape m_line;//!<Line
	sf::Vector2f vf_ballPos;//!<position of the ball
	sf::Vector2f vf_mousePos;//!<position of the mouse
	float fOrientation = 0.0f;//!<angle
	float fCurLength = 0.0f;//!<length of the drawn line
	float fMaxLength = 2.0f;//!<maximum length of the line
	bool bMouseDown = false;//!<is the mouse pressed
public:
	//! Constructor
	Control();

	//! Deconstructor
	~Control();

	//! Set the ball position
	/*!
	\param ballPos - position of the ball. */
	void setBallPos(sf::Vector2f ballPos);

	//! Set the mouse position
	/*!
	\param mousePos - position of the mouse. */
	void setMousePos(sf::Vector2f mousePos);

	//! Update
	/*!
	\param fTimestep - time taken in last frame. */
	void update(float fCurrentTime);

	//! Draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	//! toggle when the mouse is pressed / stops being pressed
	void toggleMouseDown();

	//! Check if the mouse is registered as down
	bool isMouseDown();

	//! Get the magnitude of the vector
	float getMagnitude();

	//! Get the Angle of the vector
	float getOrientation();

};

