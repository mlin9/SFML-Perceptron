#include "environment.h"

int main() {
	sf::RenderWindow window( sf::VideoMode( 1280, 800 ), "Perceptron");
	Environment environment(&window);
	environment.start();
	return 0;
}
