#pragma once
#include <Box2D/Box2D.h>

/*! \file PhysicsObject.h
* \brief Header file for PhysicsObject Class
*
*/

#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

enum collisions {
	WALL = 0x0001,
	BALL = 0x0002,
	HOLE = 0x0004,
	EMPTY = 0x0008,
};


/*! \class PhysicsObject
* \brief A basic class that all physics objects inherit from
*
*/
class PhysicsObject
{
protected:
	b2Body * m_body = nullptr;//!<Pointer to body
	const float mk_fDensity = 1.0f;//!<Density of object, mass by area
	const float mk_fFriction = 0.4f;//!<Friction of object
	const float mk_fBounciness = 0.6f;//!<Bounciness of object, percentage of momentum conserved
};

