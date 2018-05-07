/* Environment class:

- Controller for the SFML 2D Window object.
- Executes the main program loop.

PUBLIC MEMBERS:

- Environment(sf::RenderWindow *window)
Constructor for the Environment Class, accepts the rendering window as an argument.

- void Start()
Executes the main program loop.

PRIVATE MEMBERS:

- void mainLoop()
The main program loop, which will contain all execution components.

- void init()
Refreshes the rendering window.

- sf::RenderWindow *screen
Pointer variable that references the rendering window, enabling it to draw graphics.

End of Contents */

#include "environment.h"

//Constructor
Environment::Environment(sf::RenderWindow *window)
{
	screen = window;
}

Environment::~Environment()
{
	delete screen;
}

//Primer
void Environment::start()
{
	mainLoop();
}

//Main Function Loop
void Environment::mainLoop()
{
	NNetwork_field network(screen);
	network.init();
	
	while(screen->isOpen())
	{
		//Refresh Rendering Window
		init();
	
		//Handle Events
		sf::Event event;
		while(screen -> pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					screen->close();
					break;
					
				//Handle Keys (Pressed)
				case sf::Event::KeyPressed:
					
					switch(event.key.code)
					{	
						case sf::Keyboard::Escape:
							screen->close();
							break;
						case sf::Keyboard::Space:
							network.update();
							break;
						case sf::Keyboard::R:
							network.train();
							break;
						default:
							break;
					}
					break;
					
				default:
					break;
			}
		}
		
		//Render Objects
		network.draw();
		screen->display();
		screen->setFramerateLimit(60);
	}
}

//Clear Rendering
void Environment::init()
{
	screen->clear();
}
