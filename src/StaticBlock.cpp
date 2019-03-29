#include "..\include\StaticBlock.h"
/*! \file StaticBlock.cpp
* \brief Source file for StaticBlock Class.
*
*/

//! Constructor
/*!
\param world  -  Physics Worldspace.
\param position  -  position to be placed.
\param size  -  Size of shape.
\param orientation - rotation of object. */
StaticBlock::StaticBlock(b2World*  world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation)
{
	b2BodyDef l_bodyDef;//!< Used to set body definitions
	b2PolygonShape l_shape;//!< Used to set shape
	b2FixtureDef l_fixtureDef;//!< Used to set physics properties
							  
	//! Set position and angle of Hitbox
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	//! create a new body in the world
	m_body = world->CreateBody(&l_bodyDef);

	//! set the shape of the hitbox
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);

	//! set the physics properties
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fBounciness;
	l_fixtureDef.shape = &l_shape;

	//! set the objects collision category
	l_fixtureDef.filter.categoryBits = WALL;

	//! apply the properties
	m_body->CreateFixture(&l_fixtureDef);

	//! Set the SFML shape with the given parameters
	setPosition(position);
	setSize(size);
	setOrigin(size*0.5f);
	setRotation(orientation);
	setFillColor(sf::Color::Black);
}

//! Deconstructor
StaticBlock::~StaticBlock()
{
}
