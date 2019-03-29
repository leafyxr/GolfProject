 #include "..\include\HoleContactListener.h"
#include <iostream>

//! When contact begins
/*!
\param contact  -  details of the collision. */
void HoleContactListener::BeginContact(b2Contact* contact) {
	bool isSensorA = contact->GetFixtureA()->IsSensor();//!<Check if object A is a sensor
	bool isSensorB = contact->GetFixtureB()->IsSensor();//!<Check if object B is a sensor
	if (isSensorA) {
		m_hole->ballIn(true);//!<Tell the hole the ball is in
		m_ball->setDamping(0.9);//!<increase the damping on the ball
		return;
	}
	if (isSensorB) {
		m_hole->ballIn(true);//!<Tell the hole the ball is in
		m_ball->setDamping(0.9);//!<increase the damping on the ball
		return;
	}
}

// !When contact ends
/*!
\param contact  -  details of the collision. */
void HoleContactListener::EndContact(b2Contact* contact) {
	bool isSensorA = contact->GetFixtureA()->IsSensor();//!<Check if object A is a sensor
	bool isSensorB = contact->GetFixtureB()->IsSensor();//!<Check if object B is a sensor
	if (isSensorA) {
		m_hole->ballIn(false);//!<Tell the hole the ball is out
		m_ball->setDefaultDamping();//!<return ball to default damping
		return;
	}
	if (isSensorB) {
		m_hole->ballIn(false);//!<Tell the hole the ball is out
		m_ball->setDefaultDamping();//!<return ball to default damping
		return;
	}
}

//! Set the current hole sensor
/*!
\param hole  -  current hole sensor. */
void HoleContactListener::setHole(Hole *hole) {
	m_hole = hole;
}

/*!
\param ball  -  current player ball. */
void HoleContactListener::setBall(ball * Ball)
{
	m_ball = Ball;
}
