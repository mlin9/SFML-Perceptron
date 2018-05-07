#include <SFML/Graphics.hpp>
#include <cmath>
#include "nnetwork.h"

#ifndef ANN_V_H
#define ANN_V_H

#define _USE_MATH_DEFINES

class NNetwork_field
{
	public:
	NNetwork_field(sf::RenderWindow *input_window);
	void init();
	void draw();
	void update();
	void train();
	private:
	sf::RenderWindow *screen;
	sf::Font font;
	sf::Text inputs_text[NUM_INPUTS];
	sf::Text weights_text[NUM_INPUTS];
	sf::Text output_text;
	sf::Text status_text;
	sf::Text condition_text;
	sf::RectangleShape pixels[NUM_INPUTS];
	sf::RectangleShape result_box;
	sf::CircleShape input_nodes[NUM_INPUTS];
	sf::CircleShape output_node;
	sf::Vertex weight_lines[NUM_INPUTS*2];
	sf::Vertex output_line[2];
	sf::Vertex line_buffer[2];
	NNetwork network;
};

#endif
