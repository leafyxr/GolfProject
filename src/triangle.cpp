#include "..\include\triangle.h"
/*! \file triangle.cpp
* \brief Source file for triangle Class.
*
*/

//! Constructor
/*!
\param world  -  Physics Worldspace.
\param position  -  position to be placed.
\param size  -  Size of shape.
\param orientation - rotation of object. */
triangle::triangle(b2World* world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation)
{
	b2BodyDef l_bodyDef; //!< Used to set body definitions
	b2PolygonShape l_shape; //!< Used to set shape
	b2FixtureDef l_fixtureDef;//!< Used to set physics properties

	b2Vec2 Vertices[3];//!< Stores coordinates for vertices;

	//! Set vertices positions
	Vertices[0] = b2Vec2(size.x, 0.0f);
	Vertices[1] = b2Vec2(size.x, size.y);
	Vertices[2] = b2Vec2(0.0f, 0.0f);

	//! Set position and angle of Hitbox
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	//! create a new body in the world
	m_body = world->CreateBody(&l_bodyDef);

	//! set the shape of the hitbox
	l_shape.Set(Vertices, 3);

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
	setPointCount(3);
	setPoint(0, sf::Vector2f(Vertices[0].x, Vertices[0].y));
	setPoint(1, sf::Vector2f(Vertices[1].x, Vertices[1].y));
	setPoint(2, sf::Vector2f(Vertices[2].x, Vertices[2].y));
	setPosition(position);
	setOrigin(sf::Vector2f(0.0f, 0.0f));
	setRotation(orientation);
	setFillColor(sf::Color::Black);
}

//! Deconstructor
triangle::~triangle()
{
}
