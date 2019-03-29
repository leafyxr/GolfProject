#include "..\include\Game.h"
/*! \file Game.cpp
* \brief Source file for Game Class.
*
*/

//! Constructor
/*!
\param window  -  window to draw text to.
\param orientation - font to be used for text. */
Game::Game(sf::RenderWindow &window, sf::Font &font) {
	//!Set world view
	m_view.setCenter(0.f, 0.f);
	m_view.setSize(m_worldSize);

	//!Create new world with given gravity, no gravity in this instance
	m_pWorld = new b2World(mk_gravity);

	//!Create wall objects
	m_wall.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.0f, 4.0f), sf::Vector2f(16.0f, 1.0f), 0.f) );
	m_wall.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.0f, -4.0f), sf::Vector2f(16.0f, 1.0f), 0.f) );
	m_wall.push_back(StaticBlock(m_pWorld, sf::Vector2f(7.5f, 0.0f), sf::Vector2f(1.0f, 9.0f), 0.f) );
	m_wall.push_back(StaticBlock(m_pWorld, sf::Vector2f(-7.5f, 0.0f), sf::Vector2f(1.0f, 9.0f), 0.f) );
	m_wall.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.0f, 1.0f), sf::Vector2f(3.0f, 6.0f), 0.f) );

	//!Create Ball
	m_ball.push_back(ball(m_pWorld, sf::Vector2f(-4.5f, 3.0f), 0.15f, 0.f) );

	//!Create Hole
	m_hole.push_back(Hole(m_pWorld, sf::Vector2f(4.5f, 3.0f), 0.20f, 0.f) );

	//!Create Doors
	m_door.push_back(door(m_pWorld, sf::Vector2f(-1.0f, -3.35f), sf::Vector2f(1.2f, 0.2f), sf::Vector2f(-.6f, 0.0f), 90.f) );
	m_door.push_back(door(m_pWorld, sf::Vector2f(1.0f, -3.35f), sf::Vector2f(1.2f, 0.2f), sf::Vector2f(-.6f, 0.0f), 90.f) );

	//!Create corner triangles
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(-1.5f, 2.5f), sf::Vector2f(1.0f, 1.0f), 90.f) );
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(-6.0f, 3.5f), sf::Vector2f(1.0f, 1.0f), 180.f) );
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(6.0f, -3.5f), sf::Vector2f(1.0f, 1.0f), 0.f) );
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(-7.0f, -2.5f), sf::Vector2f(1.0f, 1.0f), 270.f) );
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(7.f, 2.5f), sf::Vector2f(1.0f, 1.0f), 90.0f) );
	m_triangle.push_back(triangle(m_pWorld, sf::Vector2f(2.5f,3.5f), sf::Vector2f(1.0f, 1.0f), 180.0f) );

	//!Create text boxes
	m_textBox.push_back(TextBox(window, font, sf::Vector2f(-4.0f, -4.25f), 50.0f, sf::Color::White, "Par : " + std::to_string(iPar) ) );
	m_textBox.push_back(TextBox(window, font, sf::Vector2f(4.0f, -4.25f), 50.0f, sf::Color::White, "Current : " + std::to_string(iCurr) ) );

	//!Set the contact listner & required parameters
	m_listener.setBall(&m_ball[0]);
	m_listener.setHole(&m_hole[0]);
	m_pWorld->SetContactListener(&m_listener);
}

//! Deconstructor
Game::~Game() {
	delete m_pWorld;//!<Delete pointer to world
	m_pWorld = nullptr;
}

//! returns if the mouse is pressed down
bool Game::isMouseDown() {
	return m_control.isMouseDown();
}

//! Runs when the mouse is pressed
/*!
\param l_mousePosition - position of the mouse on the screen. */
void Game::mouseDown(sf::Vector2f mousePos) {
	//! If mouse is not already down toggle it, only when the game is active
	if (!m_control.isMouseDown() && bActive) {
		m_control.toggleMouseDown();
	}
	//! Updates the ball position & mouse position for the controls
	m_control.setBallPos(m_ball[0].getPosition() );
	m_control.setMousePos(mousePos);
}

//! Runs when a mouse press stops
void Game::mouseStop() {
	//! if mouse is registered as down and game is active
	if (m_control.isMouseDown() && bActive) {
		//! toggle mouse down
		m_control.toggleMouseDown();
		//! Inrease current strokes
		iCurr++;
		//! Apply calulated force to the ball
		m_ball[0].applyForce(m_control.getMagnitude(), m_control.getOrientation() );
	}
}

//! Update
/*!
\param fTimestep - time taken in last frame. */
void Game::update(float fTimestep) {
	//! if game is active
	if (bActive) {
		//! Update the physics engine
		m_pWorld->Step(fTimestep, mk_iVelocityIterations, mk_iPositionIterations);
		//! Update the ball
		m_ball[0].update(fTimestep);
		//! Update the controls
		m_control.update(fTimestep);
		for (int i = 0; i < m_door.size(); i++) m_door[i].update(fTimestep);//!< Update all doors
		m_hole[0].update(fTimestep);//!< Update the hole
		bWin = m_hole[0].win(); //!< check if game has been won
		m_textBox[1].setString("Current : " + std::to_string(iCurr) );//!< Update text
	}
	//! if game has been won and game is active
	if (bWin && bActive) {
		for (int i = 1; i != m_textBox.size(); i = 1) {
			m_textBox.pop_back();//!< delete all other text fields apart from the first
		}
		m_textBox[0].setPosition(sf::Vector2f(0.0f, -1.0f) );//!< set the position
		m_textBox[0].setSize(100.0f);//!< set the size
		m_textBox[0].setString(winString() );//!< set the string
		m_textBox[0].setFillColor(sf::Color::White);//!< set the color
		m_textBox[0].setOutline(sf::Color::Black, 4.0f);//!< set the outline
		bActive = false;//!< set game to inactive
	}
}

//! Draw
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.setView(m_view);

	if (bActive) {//!< if game is active
		for (StaticBlock wall : m_wall) target.draw(wall);//!< draw all walls
		for (triangle triangle : m_triangle) target.draw(triangle);//!< draw all triangles
		for (door Door : m_door) target.draw(Door);//!< draw all doors

		target.draw(m_hole[0]);//!< draw hole

		target.draw(m_ball[0]);//!< draw ball

		target.draw(m_control, states);//!< draw controls
	}
}

//! Draw text 
void Game::drawText() {
	for(int i = 0; i < m_textBox.size(); i++) m_textBox[i].draw();//!< draw all text
}

// !Returns a string based on score, used for endscreen
std::string Game::winString()
{
	//! Calculates score based on distance from par, relevant string is then returned
	int iScore = iPar - iCurr;
	if (iScore >= 4) { return "Condor : -4"; }
	if (iScore == 3) { return "Albatross : -3"; }
	if (iScore == 2) { return "Eagle : -2"; }
	if (iScore == 1) { return "Birdie : -1"; }
	if (iScore == 0) { return "Par : E"; }
	if (iScore == -1) { return "Bogey : +1"; }
	if (iScore == -2) { return "Double Bogey : +2"; }
	if (iScore <= -3) { return "Triple Bogey : +3"; }
	return "ERROR - No Scoring found";
}
