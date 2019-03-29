#pragma once
#include <Box2D/Box2D.h>
#include "ball.h"
#include "Hole.h"

/*! \file HoleContactListener.h
* \brief Header file for HoleContactListener Class
*
*/


/*! \class HoleContactListener
* \brief detects contact between the ball and the hole sensor.
*
*/
class HoleContactListener : public b2ContactListener
{
private:
	Hole * m_hole = nullptr;//!<Pointer to hole sensor
	ball * m_ball = nullptr;//!<Pointer to ball sensor
public:
	//! When contact begins
	/*!
	\param contact  -  details of the collision. */
	void BeginContact(b2Contact* contact);

	//! When contact ends
	/*!
	\param contact  -  details of the collision. */
	void EndContact(b2Contact* contact);

	//! Set the current hole sensor
	/*!
	\param hole  -  current hole sensor. */
	void setHole(Hole *hole);

	//! Set the current player ball
	/*!
	\param ball  -  current player ball. */
	void setBall(ball *Ball);
};

