#include "..\include\Control.h"
#include "VectorMath.h"
/*! \file Control.cpp
* \brief Source file for Control Class.
*
*/

//! Constructor
Control::Control()
{
	//! set origin and color of the line
	m_line.setOrigin(0.01f, 0.01f);
	m_line.setFillColor(sf::Color::Blue);
}

//! Deconstructor
Control::~Control()
{
}

//! Set the ball position
/*!
\param ballPos - position of the ball. */
void Control::setBallPos(sf::Vector2f ballPos) {
	vf_ballPos = ballPos;
}

//! Set the mouse position
/*!
\param mousePos - position of the mouse. */
void Control::setMousePos(sf::Vector2f mousePos) {
	vf_mousePos = mousePos;
}

//! Update
/*!
\param fTimestep - time taken in last frame. */
void Control::update(float fCurrentTime) {
	if (bMouseDown) {//!< if mouse down
		m_line.setPosition(vf_ballPos);//!< set position of line
		sf::Vector2f l_vec = sf::Vector2f(vf_mousePos.x - vf_ballPos.x, vf_mousePos.y - vf_ballPos.y);//!< calulate vector from two points
		fCurLength = getDistance(l_vec);//!< calulate distance between points
		if (fCurLength > fMaxLength) {//!< if more than the max set as the max
			fCurLength = fMaxLength;
		}
		fOrientation = getAngle(l_vec);//!< calulate direction of vector
		m_line.setSize(sf::Vector2f(fCurLength, 0.02f));//!< set size of line
		m_line.setRotation(fOrientation * RAD2DEG);//!< set direction of line
	};
}

//! Draw
void Control::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (bMouseDown) {
		target.draw(m_line);//!< only draw line if mouse is down
	}
}

//! toggle when the mouse is pressed / stops being pressed
void Control::toggleMouseDown() {
	bMouseDown = !bMouseDown;
}

//! Check if the mouse is registered as down
bool Control::isMouseDown() {
	return bMouseDown;
}

//! Get the magnitude of the vector
float Control::getMagnitude() {
	return fCurLength;
}

//! Get the Angle of the vector
float Control::getOrientation() {
	return fOrientation;
}
