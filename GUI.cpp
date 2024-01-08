#include "GUI.h"

Gui::Gui(sf::RenderWindow &window)
	: m_Window(window)
{
}

Gui::~Gui()
{
}

bool Gui::initGui(sf::Font &font)
{
	m_playerScore[0] = 0;
	m_playerScore[1] = 0;
	for (int i = 0; i < 2; i++)
	{
		m_textPlayer[i].setString("Score: 0");
		m_textPlayer[i].setFont(font);
		m_textPlayer[i].setFillColor(sf::Color::White);
	}
	m_textPlayer[0].setPosition(0.f, 0.f);
	m_textPlayer[1].setPosition(
			m_Window.getSize().x
			- m_textPlayer[1].getGlobalBounds().width,
			0.f);
	return (true);
}

void Gui::updateStats(int playerWhoScored)
{
	std::cout << "Player who scored: "<< playerWhoScored << std::endl;
	std::stringstream ss;
	std::cout << "score0: "<< m_playerScore[0] << std::endl;
	std::cout << "score1: "<< m_playerScore[1] << std::endl;
	m_playerScore[playerWhoScored]++;
	std::cout << "1score0: "<< m_playerScore[0] << std::endl;
	std::cout << "1score1: "<< m_playerScore[1] << std::endl;
	ss << "Score: " << m_playerScore[playerWhoScored];
	std::cout << "2score0: "<< m_playerScore[0] << std::endl;
	std::cout << "2score1: "<< m_playerScore[1] << std::endl;
	m_textPlayer[playerWhoScored].setString(ss.str());
	std::cout << "3score0: "<< m_playerScore[0] << std::endl;
	std::cout << "3score1: "<< m_playerScore[1] << std::endl;
	if (playerWhoScored > 0)
	{
		m_textPlayer[playerWhoScored].setPosition(
			m_Window.getSize().x
			- m_textPlayer[playerWhoScored].getGlobalBounds().width,
			0.f);
	}
	std::cout << "4score0: "<< m_playerScore[0] << std::endl;
	std::cout << "4score1: "<< m_playerScore[1] << std::endl;
}

// inits
void Gui::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_textPlayer[0]);
	target.draw(m_textPlayer[1]);
}
