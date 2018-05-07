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

#include <SFML/Graphics.hpp>

#include "nnetwork_field.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment
{
	public:
		//Constructor
		Environment(sf::RenderWindow *window);
		~Environment();
		//Primer
		void start();
	private:
		//Main Program Loop
		void mainLoop();
		//Clear Rendering
		void init();
		//Render Window Pointer
		sf::RenderWindow *screen;
};

#endif
