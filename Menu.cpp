#include "Menu.h"
Menu::Menu(sf::RenderWindow	&window)
	: m_Window(window)
{
}

Menu::~Menu()
{
}


//init
bool Menu::initMenu(sf::Vector2f windowSize, sf::Font &font)
{
	m_header.setFont(font);
	m_header.setFillColor(sf::Color::White);
	m_header.setString("Tic-Tac-Toe");
	m_header.setCharacterSize(50);
	m_header.setPosition(
		windowSize.x/2 - m_header.getGlobalBounds().width / 2,
		windowSize.y/4*1 - m_header.getGlobalBounds().height / 2
	);
	
	m_menuItems[0].setFont(font);
	m_menuItems[0].setFillColor(sf::Color::Red);
	m_menuItems[0].setString("Play");
	m_menuItems[0].setPosition(
		windowSize.x/2 - m_menuItems[0].getGlobalBounds().width / 2,
		windowSize.y/4*2 - m_menuItems[0].getGlobalBounds().height / 2
	);


	m_menuItems[1].setFont(font);
	m_menuItems[1].setFillColor(sf::Color::White);
	m_menuItems[1].setString("Exit");
	m_menuItems[1].setPosition(
		windowSize.x/2 - m_menuItems[1].getGlobalBounds().width / 2,
		windowSize.y/4*3 - m_menuItems[1].getGlobalBounds().height / 2
	);

	return (true);
}

//accessors
bool Menu::isButtonPlay(const sf::Vector2i &mousePos)
{
	if (m_menuItems[0].getGlobalBounds().contains(
		static_cast<sf::Vector2f>(mousePos)))
		return (true);
	return false;
}

bool Menu::isButtonQuit(const sf::Vector2i &mousePos)
{
	if (m_menuItems[1].getGlobalBounds().contains(
		static_cast<sf::Vector2f>(mousePos)))
		return (true);
	return false;
}


//modifiers
void Menu::setHeader(std::string headerString)
{
	m_header.setString(headerString);
	m_header.setPosition(
		m_Window.getSize().x/2 - m_header.getGlobalBounds().width / 2,
		m_Window.getSize().y/4*1 - m_header.getGlobalBounds().height / 2
	);
}


//functions
void Menu::update(const sf::Vector2i &mousePos)
{
	if (isButtonPlay(mousePos))
	{
		m_menuItems[0].setFillColor(sf::Color::Red);
		m_menuItems[1].setFillColor(sf::Color::White);
	}
	else if (isButtonQuit(mousePos))
	{
		m_menuItems[1].setFillColor(sf::Color::Red);
		m_menuItems[0].setFillColor(sf::Color::White);
	}
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_header);
	target.draw(m_menuItems[0]);
	target.draw(m_menuItems[1]);
}
