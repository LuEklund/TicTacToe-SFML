#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <sstream>

class Gui : public sf::Drawable
{
private:
	//the window
	sf::RenderWindow	&m_Window;

	//the displayable elements
	sf::Text			m_textPlayer[2];
	int					m_playerScore[2];


public:
	Gui(sf::RenderWindow &m_Window);
	~Gui();

	//inits
	bool	initGui(sf::Font &font);

	//functions
	void	updateStats(int	playerWhoScored);

	void	draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


