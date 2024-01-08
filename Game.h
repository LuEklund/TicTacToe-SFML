#pragma once

#include "Menu.h"
#include "Field.h"
#include "GUI.h"

enum class State
{
	PLAYING,
	PAUSED,
	GAMEOVER
};

class Game : public sf::Drawable

{
private:
	//Essentails
	State				m_state;
	sf::Font			m_font;
	sf::RenderWindow	&m_Window;
	sf::Clock			m_clock;
	float				dt;

	//Menu
	std::unique_ptr<Menu>	m_pMenu;

	//Gui
	std::unique_ptr<Gui>	m_pGui;

	//Field
	std::unique_ptr<Field>	m_pField;
	static const int		MAX_PLAYERS = 2;
	char					m_players[MAX_PLAYERS];
	int						m_playerTurn;
	int						m_playerScore[2];


public:
	Game(sf::RenderWindow &window);
	~Game();

	//inits
	bool	initGame();

	//Functions
	void	isMouseButtonReleased(sf::Mouse::Button button);
	void	isKeyReleased(sf::Keyboard::Key key);

	void	update();
	void	draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

