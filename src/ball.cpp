#include "..\include\ball.h"
#include "VectorMath.h"
/*! \file ball.cpp
* \brief Source file for ball Class,
*
*/

//! Constructor
/*!
\param world  -  Physics Worldspace.
\param position  -  position to be placed.
\param radius  -  radius of circle.
\param orientation - rotation of object. */
ball::ball(b2World* world, const sf::Vector2f position, const float radius, const float orientation){
	b2BodyDef l_bodyDef;//!< Used to set body definitions
	b2CircleShape l_shape;//!< Used to set shape
	b2FixtureDef l_fixtureDef;//!< Used to set physics properties

	//Set body as dynamic, exterior forces can act
	l_bodyDef.type = b2_dynamicBody;

	// !Set position and angle of Hitbox
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	//! create a new body in the world
	m_body = world->CreateBody(&l_bodyDef);

	//! set the shape of the hitbox
	l_shape.m_radius = radius;

	//! set the physics properties
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fBounciness;
	l_fixtureDef.shape = &l_shape;

	//! set the objects collision category
	l_fixtureDef.filter.categoryBits = BALL;

	//! apply the properties
	m_body->CreateFixture(&l_fixtureDef);

	//! Set a default amount of damping on the ball
	m_body->SetLinearDamping(m_fDefaultDamping);

	//! Set the SFML shape with the given parameters
	setPosition(position);
	setRadius(radius);
	setOrigin(radius, radius);
	setRotation(orientation);
	setFillColor(sf::Color::White);
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(.02f);
}

//! Deconstructor
ball::~ball(){

}

//! Update
/*!
\param fTimestep - time taken in last frame. */
void ball::update(float fCurrentTime) {
	//! Updates the SFML shape to match the position and angle of the hitbox
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);
	
}

//! Apply a force to the ball
/*!
\param magnitude - Magnitude of force
\param angle - direction of force. */
void ball::applyForce(float magnitude, float angle) {
	m_body->ApplyLinearImpulse(-getVector2D(magnitude * m_fVelocityModifier, angle) ,m_body->GetWorldCenter(), true);

}

//! Set the ball damping
/*!
\param Damp - amount of damping to be set. */
void ball::setDamping(float Damp)
{
	m_body->SetLinearDamping(Damp);
}

//! Set the ball Damping to a default.
void ball::setDefaultDamping()
{
	m_body->SetLinearDamping(m_fDefaultDamping);
}
