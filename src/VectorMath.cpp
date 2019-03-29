#include "..\include\VectorMath.h"
/*! \file VectorMath.cpp
* \brief Source file for some maths involving vectors in SFML and Box2D.
*
*/


//! Converts a Box2D vector to an SFML vector
/*!
\param vec  -  Vector to be Converted.*/
sf::Vector2f convertVector(b2Vec2 vec) {
	return sf::Vector2f(vec.x, vec.y);
}

//! Converts a SFML vector to a Box2D vector
/*!
\param vec  -  Vector to be Converted.*/
b2Vec2 convertVector(sf::Vector2f vec) {
	return b2Vec2(vec.x, vec.y);
}

//! Calculates the vector angle from a Box2D vector
/*!
\param vec  -  Vector to get the angle from.*/
float getAngle(b2Vec2 vec) {
	float angle = vec.x / sqrt(powf(vec.x, 2) + powf(vec.y, 2));//!< Calulates cos(angle)
	angle = acosf(angle);//!<  Calulates angle
	if (vec.y < 0) {
		angle = -angle;//!< If y velocity is negative set the angle as a negative
	}
	return angle;
}

// !Calculates the vector angle from a SFML vector
/*!
\param vec  -  Vector to get the angle from.*/
float getAngle(sf::Vector2f vec) {
	float angle = vec.x / sqrt(powf(vec.x, 2) + powf(vec.y, 2));//!< Calulates cos(angle)
	angle = acosf(angle);//!<  Calulates angle
	if (vec.y < 0) {
		angle = -angle;//!< If y velocity is negative set the angle as a negative
	}
	return angle;
}

//! Calulates the magnitude of a Box2D vector
/*!
\param vec  -  Vector to get the magnitude from.*/
float getDistance(b2Vec2 vec) {
	float dist = sqrt(powf(vec.x, 2) + powf(vec.y, 2));//!< Calulates the magnitude
	return dist;
}

//! Calculates the magnitude of a SMFL vector
/*!
\param vec  -  Vector to get the magnitude from.*/
float getDistance(sf::Vector2f vec) {
	float dist = sqrt(powf(vec.x, 2) + powf(vec.y, 2));//!< Calulates the magnitude
	return dist;
}


//! Calculates a SFML vector from a magnitude and angle
/*!
\param vec  -  Magnitude of the vector.
\param angle - angle of vector. */
sf::Vector2f getVectorSf2D(float magnitude, float angle) {
	float l_fXcomp = cos(angle)*magnitude;//!< Calulates the x component
	float l_fYcomp = sin(angle)*magnitude;//!< Calulates the y component
	sf::Vector2f l_vector = sf::Vector2f(l_fXcomp, l_fYcomp);//!< puts the vector together
	return l_vector;
}

//! Calulates a Box2D vector from a magnitude and angle
/*!
\param vec  -  Magnitude of the vector.
\param angle - angle of vector. */
b2Vec2 getVector2D(float magnitude, float angle) {
	float l_fXcomp = cos(angle)*magnitude;//!< Calulates the x component
	float l_fYcomp = sin(angle)*magnitude;//!< Calulates the y component
	b2Vec2 l_vector = b2Vec2(l_fXcomp, l_fYcomp);//!< puts the vector together
	return l_vector;
}

