#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

/*! \file VectorMath.h
* \brief Header file for some maths involving vectors in SFML and Box2D.
*
*/

#define DEG2RAD 0.017453f //!< Conversion from Degrees to Radians.
#define RAD2DEG 57.29577f //!< Conversion from Radians to Degrees.

//! Converts a Box2D vector to an SFML vector
/*!
\param vec  -  Vector to be Converted.*/
sf::Vector2f convertVector(b2Vec2 vec);

//! Converts a SFML vector to a Box2D vector
/*!
\param vec  -  Vector to be Converted.*/
b2Vec2 convertVector(sf::Vector2f vec);

//! Calculates the vector angle from a Box2D vector
/*!
\param vec  -  Vector to get the angle from.*/
float getAngle(b2Vec2 vec);

//! Calculates the vector angle from a SFML vector
/*!
\param vec  -  Vector to get the angle from.*/
float getAngle(sf::Vector2f vec);

//! Calulates the magnitude of a Box2D vector
/*!
\param vec  -  Vector to get the magnitude from.*/
float getDistance(b2Vec2 vec);

//! Calculates the magnitude of a SMFL vector
/*!
\param vec  -  Vector to get the magnitude from.*/
float getDistance(sf::Vector2f vec);

//! Calculates a SFML vector from a magnitude and angle
/*!
\param vec  -  Magnitude of the vector.
\param angle - angle of vector. */
sf::Vector2f getVectorSf2D(float magnitude, float angle);

//! Calulates a Box2D vector from a magnitude and angle
/*!
\param vec  -  Magnitude of the vector.
\param angle - angle of vector. */
b2Vec2 getVector2D(float magnitude, float angle);



