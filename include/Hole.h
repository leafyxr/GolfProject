#pragma once
#include<SFML/Graphics.hpp>
#include<Box2D/Box2D.h>
#include"PhysicsObject.h"

/*! \file Hole.h
* \brief Header file for Hole Class
*
*/

/*! \class Hole
* \brief A Sensor that acts as a goal point.
*
*/
class Hole : public sf::CircleShape, public PhysicsObject
{
private:
	bool bWin = false;//!<Boolean for if the goal has been reached
	bool bBallIn = false;//!<Boolean for if the ball is in the sensor
	float timer = 0.0f;//!<Timer
	float timelimit = 1.0f;//!<Time limit
public:
	//! Constructor
	/*!
	\param world  -  Physics Worldspace.
	\param position  -  position to be placed.
	\param radius  -  radius of circle.
	\param orientation - rotation of object. */
	Hole(b2World* world, const sf::Vector2f position, const float radius, const float orientation);

	//! Deconstructor
	~Hole();

	//! Update
	/*!
	\param fTimestep - time taken in the last frame. */
	void update(float fTimestep);

	//! Tell the hole that the ball has entered
	/*!
	\param isBallIn -  Is the ball in the hole. */
	void ballIn(bool isBallIn);
		
	//! Returns if the game has been won
	bool win();
};

