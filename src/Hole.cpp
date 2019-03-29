#include "..\include\Hole.h"
/*! \file Hole.cpp
* \brief Source file for Hole Class
*
*/

//! Constructor
/*!
\param world  -  Physics Worldspace.
\param position  -  position to be placed.
\param radius  -  radius of circle.
\param orientation - rotation of object. */
Hole::Hole(b2World* world, const sf::Vector2f position, const float radius, const float orientation)
{
	b2BodyDef l_bodyDef;//!< Used to set body definitions
	b2CircleShape l_shape;//!< Used to set shape
	b2FixtureDef l_fixtureDef;//!< Used to set physics properties

	//! Set position and angle of Hitbox
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	//! create a new body in the world
	m_body = world->CreateBody(&l_bodyDef);

	//! set the radius of the hitbox
	l_shape.m_radius = radius;

	//! set the physics properties
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fBounciness;
	l_fixtureDef.shape = &l_shape;

	//! set as a sensor
	l_fixtureDef.isSensor = true;

	//! set the objects collision category
	l_fixtureDef.filter.categoryBits = HOLE;

	//! set the sensor to only detect objects tagged with BALL
	l_fixtureDef.filter.maskBits = BALL;

	//! apply the properties
	m_body->CreateFixture(&l_fixtureDef);

	//! Set the SFML shape with the given parameters
	setPosition(position);
	setRadius(radius);
	setOrigin(radius, radius);
	setRotation(orientation);
	setFillColor(sf::Color::Black);
	setOutlineColor(sf::Color(87,54,22));
	setOutlineThickness(.04f);
}

//! Deconstructor
Hole::~Hole()
{
}

//! Update
/*!
\param fTimestep - time taken in the last frame. */
void Hole::update(float fTimestep) {
	if (bBallIn) {//!<If ball is in start timer
		timer += fTimestep;
		if (timer >= timelimit) {//!<if time limit is reached set win to be true
			bWin = true;
		}
	}
}

//! Tell the hole that the ball has entered
/*!
\param isBallIn -  Is the ball in the hole. */
void Hole::ballIn(bool isBallIn) {
	bBallIn = isBallIn;
	timer = 0.0;//!<Reset time
}

//! Returns if the game has been won
bool Hole::win() {
	return bWin;
}
