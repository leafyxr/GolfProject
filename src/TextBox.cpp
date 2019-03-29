#include "..\include\TextBox.h"
/*! \file TextBox.cpp
* \brief Source file for TextBox Class.
*
*/

//! Constructor
/*!
\param window  -  Window to be drawn in.
\param font  -  font to be used.
\param pos  -  position of the text.
\param size  -  character size.
\param color  -  fill color of the text.
\param text - string to be displayed. */
TextBox::TextBox(sf::RenderWindow &window, sf::Font &font, sf::Vector2f pos, int size, sf::Color color, std::string text) : m_font(font), m_window(window) {
	m_text = sf::Text(text, m_font);//!< sets the font and string
	m_text.setPosition(pos);//!< sets the position
	m_text.setCharacterSize(size);//!< sets the character sizw
	m_text.setScale(sf::Vector2f(0.01f, 0.01f));//!< sets thye scale to better fit on the screen
	m_text.setFillColor(color);//!< sets the fill color
	m_text.setOrigin(m_text.getLocalBounds().width/2.0f, m_text.getLocalBounds().height/2.0f);//!< sets the origin to be the center of the drawn text
}

//! Deconstructor
TextBox::~TextBox() {

}

//! Sets the fill color of the text
/*!
\param color  -  fill color of the text. */
void TextBox::setFillColor(sf::Color color)
{
	m_text.setFillColor(color);//!< Set the fill color
}

//! Sets the outline color and weight
/*!
\param color  -  outline color.
\param param size  -  outline weight. */
void TextBox::setOutline(sf::Color color, float size)
{
	m_text.setOutlineColor(color);//!< set the outline color
	m_text.setOutlineThickness(size);//!<  set the outline thickness
}

//! sets the string 
/*!
\param text - string to be displayed. */
void TextBox::setString(std::string text) {
	m_text.setString(text);//!< set the text to be displayed
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);//!< resets the origin
}

//! sets the position
/*!
\param position  -  position to be placed. */
void TextBox::setPosition(sf::Vector2f pos)
{
	m_text.setPosition(pos);//!< sets the position
}

//! sets the character size
/*!
\param size  -  character size. */
void TextBox::setSize(int size)
{
	m_text.setCharacterSize(size);//!< set the character size
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);//!< resets the origin
}

//! draws the text
void TextBox::draw() {
	m_window.draw(m_text);
}