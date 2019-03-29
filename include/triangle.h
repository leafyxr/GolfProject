#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "PhysicsObject.h"

/*! \file triangle.h
* \brief Header file for triangle Class.
*
*/

/*! \class triangle
* \brief Creates a static triangle shape.
*
*/
class triangle : public sf::ConvexShape, public PhysicsObject
{
public:
	//! Constructor
	/*!
	\param world  -  Physics Worldspace.
	\param position  -  position to be placed.
	\param size  -  Size of shape.
	\param orientation - rotation of object. */
	triangle(b2World* world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation);

	//! Deconstructor
	~triangle();
};

