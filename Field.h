#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Field : public sf::Drawable
{
private:
	//the window
	sf::RenderWindow	&m_Window;

	//for the field
	// char				m_field[3][3];
	float				m_cellSize;
	sf::Text			m_symbol[3][3];
	sf::RectangleShape	m_squares[3][3];

	//private functions
	bool	wasPressed(const sf::RectangleShape &square, const sf::Vector2i &mousePos);

public:
	Field(sf::RenderWindow &m_Window);
	~Field();

	//inits
	bool	initField(sf::Font &font);

	//functions
	bool	stalemate();
	void	resetField();
	bool	winningCondition(char player);
	bool	isMouseButtonReleased(const sf::Vector2i &mousePos, char player);
	
	void	draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


