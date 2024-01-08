#include "Game.h"
Game::Game(sf::RenderWindow &window)
	: m_Window(window)
	, m_pMenu(std::make_unique<Menu>(window))
	, m_pField(std::make_unique<Field>(window))
	, m_pGui(std::make_unique<Gui>(window))
{
}

Game::~Game()
{
}

bool Game::initGame()
{
	m_players[0] = 'X';
	m_players[1] = 'O';
	m_playerTurn = 0;
	m_state = State::PAUSED;
	if(!m_font.loadFromFile("assets/Dalmation-FREE.otf"))
	{
		std::cout << "ERROR::FONT::FILE_NOT_FOUND" << std::endl;
		return (false);
	}
	if(!m_pMenu->initMenu(static_cast<sf::Vector2f>(m_Window.getSize()), m_font))
		return false;
	if(!m_pField->initField(m_font))
		return false;
	if (!m_pGui->initGui(m_font))
		return false;
	return (true);
}

void Game::isMouseButtonReleased(sf::Mouse::Button button)
{

	switch (m_state)
	{
	case State::PAUSED:
		if (m_pMenu->isButtonPlay(sf::Mouse::getPosition(m_Window)))
			m_state = State::PLAYING;
		else if (m_pMenu->isButtonQuit(sf::Mouse::getPosition(m_Window)))
			m_Window.close();
		break;
	case State::GAMEOVER:
		if (m_pMenu->isButtonPlay(sf::Mouse::getPosition(m_Window)))
		{
			m_pField->resetField();
			m_state = State::PLAYING;
		}
		else if (m_pMenu->isButtonQuit(sf::Mouse::getPosition(m_Window)))
			m_Window.close();
		break;
	case State::PLAYING:
		if (m_pField->isMouseButtonReleased(sf::Mouse::getPosition(m_Window), m_players[m_playerTurn]))
		{
			if (m_pField->winningCondition(m_players[m_playerTurn]))
			{
				m_state = State::GAMEOVER;
				m_pGui->updateStats(m_playerTurn);
				m_pMenu->setHeader("GAMEOVER!");
			}
			if (m_pField->stalemate())
			{
				m_state = State::GAMEOVER;
				m_pMenu->setHeader("STALEMATE!");
			}
			m_playerTurn++;
			if (m_playerTurn >= MAX_PLAYERS)
				m_playerTurn = 0;
		}
		break;
	}
}

void Game::isKeyReleased(sf::Keyboard::Key key)
{
	switch (m_state)
	{
	case State::PLAYING:

		switch (key)
		{
		case sf::Keyboard::Escape:
			m_state = State::PAUSED;
			break;
		}
		break;
	}
}

void Game::update()
{
	switch (m_state)
	{
	case State::PAUSED:
		m_pMenu->update(sf::Mouse::getPosition(m_Window));
		break;
	case State::GAMEOVER:
		m_pMenu->update(sf::Mouse::getPosition(m_Window));
		break;
	}
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	switch (m_state)
	{
	case State::PAUSED:
		target.draw(*m_pMenu.get());
		break;
	case State::GAMEOVER:
		target.draw(*m_pGui.get());
		target.draw(*m_pMenu.get());
		break;
	case State::PLAYING:
		target.draw(*m_pField.get());
		target.draw(*m_pGui.get());
		break;
	}
	
}
