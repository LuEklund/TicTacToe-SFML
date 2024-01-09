#include "Field.h"

//private functions
bool	Field::wasPressed(const sf::RectangleShape &square, const sf::Vector2i &mousePos)
{
	if (square.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
		return true;
	return false;
}

Field::Field(sf::RenderWindow &window)
	: m_Window(window)
{

}

Field::~Field()
{
}

//inits
bool Field::initField(sf::Font &font)
{
	m_cellSize = 50.f;
	//Calculate the starting postion for our field to be spawn in.
	//so it will be drawn in the center
	int	winX = m_Window.getSize().x / 2 - static_cast<int>(m_cellSize * 1.5f);
	int	winY = m_Window.getSize().y / 2 - static_cast<int>(m_cellSize * 1.5f);


	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			m_squares[x][y].setFillColor(sf::Color(155,155,155,255));
			m_squares[x][y].setOutlineColor(sf::Color::White);
			m_squares[x][y].setOutlineThickness(-1.f);
			m_squares[x][y].setSize(sf::Vector2f(50.f,50.f));
			m_squares[x][y].setPosition(0.f,0.f);
			m_squares[x][y].setPosition(winX + x * m_cellSize, winY + y * m_cellSize);

			m_symbol[x][y].setFont(font);
			m_symbol[x][y].setPosition( winX + x * m_cellSize + (m_cellSize/2) - 10, winY + y * m_cellSize + (m_cellSize/2) - 30);
			m_symbol[x][y].setFillColor(sf::Color::White);
			m_symbol[x][y].setCharacterSize(50);
			m_symbol[x][y].setString("");
		}
	}
	
	return true;
}



bool Field::stalemate()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if (m_symbol[x][y].getString().isEmpty())
				return false;
		}
	}
	return (true);
}

void Field::resetField()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			m_symbol[x][y].setString("");
		}
	}
}

//functions
bool	Field::winningCondition(char player)
{
	std::string		playerStr(1, player);
	//Vertical checks
	for (int x = 0; x < 3; x++)
	{
		if (m_symbol[x][0].getString() == playerStr
		&&	m_symbol[x][1].getString() == playerStr
		&&	m_symbol[x][2].getString() == playerStr)
			return (true);
	}
	//horizontal checks
	for (int y = 0; y < 3; y++)	
	{
		if (m_symbol[0][y].getString() == playerStr
		&&	m_symbol[1][y].getString() == playerStr
		&&	m_symbol[2][y].getString() == playerStr)
			return (true);
	}
	//top-left to bottom-right
	if (m_symbol[0][0].getString() == playerStr
	&&	m_symbol[1][1].getString() == playerStr
	&&	m_symbol[2][2].getString() == playerStr)
		return (true);
	
	//top-right to bottom-left
	if (m_symbol[2][0].getString() == playerStr
	&&	m_symbol[1][1].getString() == playerStr
	&&	m_symbol[0][2].getString() == playerStr)
		return (true);
	
	return (false);

}

bool Field::isMouseButtonReleased(const sf::Vector2i &mousePos, char player)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if (wasPressed(m_squares[x][y], mousePos))
			{
				if (m_symbol[x][y].getString().isEmpty())
				{
					std::cout << "x: " << x << ", y: " << y << ", = player char: " << player << std::endl;
					m_symbol[x][y].setString(std::string(1, player));
					return (true);
				}
				else
				{
					std::string t =  m_symbol[x][y].getString();
						std::cout << "string: [" << t << "]" <<std::endl;
					std::cout << "x: " << x << ", y: " << y << ", was occupied" << std::endl;
					return (false);
				}
			}
			
		}
	}
}

void Field::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			target.draw(m_squares[x][y]);
		}
	}
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if (!m_symbol[x][y].getString().isEmpty())
			{
				target.draw(m_symbol[x][y]);
			}
		}
	}
	
}

