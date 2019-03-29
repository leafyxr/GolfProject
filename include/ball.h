#pragma once
#include<SFML/Graphics.hpp>
#include<BOX2D/Box2D.h>
#include"PhysicsObject.h"

/*! \file ball.h
* \brief Header file for ball Class,
*
*/

/*! \class ball
* \brief a dynamic ball with physics, controlled by the player.
*
*/
class ball : public sf::CircleShape, public PhysicsObject
{
private:
	float m_fVelocityModifier = 0.5f;//!<Velocity Modifier 
	float m_fDefaultDamping = 0.6;//!<Default amount of linear damping
public:
	//! Constructor
	/*!
	\param world  -  Physics Worldspace.
	\param position  -  position to be placed.
	\param radius  -  radius of circle.
	\param orientation - rotation of object. */
	ball(b2World* world, const sf::Vector2f position, const float radius, const float orientation);

	//! Deconstructor
	~ball();

	//! Update
	/*!
	\param fTimestep - time taken in last frame. */
	void update(float fCurrentTime);

	//! Apply a force to the ball
	/*!
	\param magnitude - Magnitude of force
	\param angle - direction of force. */
	void applyForce(float magnitude, float angle);

	//! Set the ball damping
	/*!
	\param Damp - amount of damping to be set. */
	void setDamping(float Damp);

	//! Set the ball Damping to a default.
	void setDefaultDamping();
};

