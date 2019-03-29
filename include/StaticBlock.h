#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "PhysicsObject.h"

/*! \file StaticBlock.h
* \brief Header file for StaticBlock Class.
*
*/

/*! \class StaticBlock
* \brief Creates a static block.
*
*/
class StaticBlock : public sf::RectangleShape , public PhysicsObject
{
public:
	//! Constructor
	/*!
	\param world  -  Physics Worldspace.
	\param position  -  position to be placed.
	\param size  -  Size of shape.
	\param orientation - rotation of object. */
	StaticBlock(b2World* world,const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation);

	//! Deconstructor
	~StaticBlock();
};

