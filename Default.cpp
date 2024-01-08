#include "Game.h"

int main()
{
	//init essential window and event for the game
    sf::RenderWindow window(sf::VideoMode(640, 480), "test");
    sf::Event event;

	//our cool game manager
	Game game(window);

	//close the program if out cool agmes fails to init
	if (!game.initGame())
		return (-1);


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyReleased)
				game.isKeyReleased(event.key.code);
			if (event.type == sf::Event::MouseButtonReleased)
				game.isMouseButtonReleased(event.mouseButton.button);
        }
		game.update();
		window.clear();
		window.draw(game);
		window.display();
    }
}

