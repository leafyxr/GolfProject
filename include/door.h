#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "PhysicsObject.h"

/*! \file door.h
* \brief Header file for Door Class.
*
*/

/*! \class door
* \brief a revolving door with physics.
*
*/
class door : public sf::Drawable, public PhysicsObject
{
private:
	float mk_fBounciness = 0.1f;//!<Bounciness of object, percentage of momentum conserved
	sf::RectangleShape m_rect;//!<Door shape
	b2Body * m_anchor;//!<Anchor point
	b2RevoluteJoint * m_joint;//!<joint
public:
	//! Constructor
	/*!
	\param world  -  Physics Worldspace.
	\param position  -  position to be placed.
	\param size  -  Size of shape.
	\param anchor  -  point to be anchored from, relative to the unrotated shape.
	\param orientation - rotation of object. */
	door(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation);

	//! Deconstructor
	~door();

	//! Draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//! Update
	/*!
	\param fTimestep - time taken in last frame. */
	void update(float fTimestep);
};

