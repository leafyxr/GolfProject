#pragma once
#include <SFML/Graphics.hpp>

/*! \file TextBox.h
* \brief Header file for TextBox Class.
*
*/

/*! \class TextBox
* \brief used to create text.
*
*/
class TextBox
{
private:
	sf::RenderWindow &m_window;//!<window to be drawn to
	sf::Text m_text;//!<Text to draw
	sf::Font &m_font;//!<Font to be used
public:
	//! Constructor
	/*!
	\param window  -  Window to be drawn in.
	\param font  -  font to be used.
	\param pos  -  position of the text.
	\param size  -  character size.
	\param color  -  fill color of the text.
	\param text - string to be displayed. */
	TextBox(sf::RenderWindow &window, sf::Font &font, sf::Vector2f pos, int size, sf::Color color, std::string text);

	//! Deconstructor
	~TextBox();

	//! Sets the fill color of the text
	/*!
	\param color  -  fill color of the text. */
	void setFillColor(sf::Color color);

	//! Sets the outline color and weight
	/*!
	\param color  -  outline color.
	\param param size  -  outline weight. */
	void setOutline(sf::Color color, float size);

	//! sets the string 
	/*!
	\param text - string to be displayed. */
	void setString(std::string text);

	//! sets the position
	/*!
	\param position  -  position to be placed. */
	void setPosition(sf::Vector2f pos);

	//! sets the character size
	/*!
	\param size  -  character size. */
	void setSize(int size);

	//! draws the text
	void draw();
};

