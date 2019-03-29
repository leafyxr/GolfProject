#include "..\include\door.h"
#include <iostream>;
/*! \file door.cpp
* \brief Source file for Door Class.
*
*/

//! Constructor
/*!
\param world  -  Physics Worldspace.
\param position  -  position to be placed.
\param size  -  Size of shape.
\param anchor  -  point to be anchored from, relative to the unrotated shape.
\param orientation - rotation of object. */
door::door(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation)
{
	b2BodyDef l_bodyDef;//!< Used to set body definitions
	b2PolygonShape l_shape;//!< Used to set shape of main door object
	b2FixtureDef l_fixtureDef;//!< Used to set physics properties
	b2CircleShape l_circ;//!< Used to set shape of anchor
	b2RevoluteJointDef jointDef;//!< Used to set joint properties

	//! Set position and angle of Hitbox
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	//! Set as a dynamic object, exterior forces can influence it
	l_bodyDef.type = b2_dynamicBody;

	// !set the shape of the hitbox
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	//! set the physics properties
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fBounciness;
	l_fixtureDef.shape = &l_shape;

	//! create a new body in the world
	m_body = world->CreateBody(&l_bodyDef);

	//! apply the properties to the body
	m_body->CreateFixture(&l_fixtureDef);

	//! keeps the joint from rotating forever
	m_body->SetAngularDamping(.1f);

	//! set anchor to be static, no forces can act
	l_bodyDef.type = b2_staticBody;

	//! set the size of the anchor to be half of the smallest size parameter
	l_circ.m_radius = fminf(size.x / 2.0f, size.y / 2.0f);
	l_fixtureDef.shape = &l_circ;

	//! create a new body in the world for the anchor
	m_anchor = world->CreateBody(&l_bodyDef);

	//! apply the properties to the anchor
	m_anchor->CreateFixture(&l_fixtureDef);
	
	jointDef.bodyA = m_anchor;//!< set the anchor as bodyA
	jointDef.bodyB = m_body;//!< set the body as bodyB
	jointDef.collideConnected = false;//!<Anchor and body cant collide
	jointDef.localAnchorA.Set(0.f, 0.f);//!<joint is connected to center of the anchor
	jointDef.localAnchorB.Set(anchor.x, anchor.y);//!<joint is connected do designated anchor point
	m_joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);//!<Create the joint with desired properties

	//! Set the SFML shape with the given parameters for the base body
	m_rect.setPosition(position);
	m_rect.setSize(size);
	m_rect.setOrigin(size*0.5f);
	m_rect.setRotation(orientation);
	m_rect.setFillColor(sf::Color::Yellow);
}

//! Deconstructor
door::~door()
{
}

//! Draw
void door::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(m_rect);
}

//! Update
/*!
\param fTimestep - time taken in last frame. */
void door::update(float fTimestep)
{
	//! Updates the SFML shape to match the position and angle of the hitbox
	b2Vec2 pos = m_body->GetPosition();
	m_rect.setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	m_rect.setRotation(angle);
}