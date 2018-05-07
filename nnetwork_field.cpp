#include "nnetwork_field.h"

NNetwork_field::NNetwork_field(sf::RenderWindow *input_window)
{
	screen = input_window;

	if (!font.loadFromFile("TNR.ttf"))
	{
		exit(EXIT_FAILURE);
	}
}

void NNetwork_field::init()
{
	sf::Vector2u dim = screen->getSize();
	float width = dim.x;
	float height = dim.y;

	int rect_length = 50;
	int char_length = rect_length/2;
	float pos_x, pos_y;

	for(int i = 0; i < NUM_INPUTS; i++)
	{
		pos_x = (width/5) + ((rect_length) * cos((i * M_PI/2) + M_PI/4));
		pos_y = (height/2) + ((rect_length) * sin((i * M_PI/2) + M_PI/4));

		pixels[i].setSize(sf::Vector2f(rect_length, rect_length));
		pixels[i].setOrigin(rect_length/2, rect_length/2);
		pixels[i].setPosition(pos_x, pos_y);
		pixels[i].setFillColor(sf::Color::White);

		pos_x = 2*(width/5);
		pos_y = i*(height/5) + (height/5);

		input_nodes[i].setRadius(rect_length/2);
		input_nodes[i].setOrigin(rect_length/2, rect_length/2);
		input_nodes[i].setPosition(pos_x, pos_y);
		input_nodes[i].setFillColor(sf::Color::White);
		weight_lines[i*2] = sf::Vector2f(pos_x, pos_y);
		weight_lines[i*2].color = sf::Color::Red;
		weight_lines[(i*2)+1] = sf::Vector2f(3*width/5, height/2);
		weight_lines[(i*2)+1].color = sf::Color::Red;
		weights_text[i].setFont(font);
		weights_text[i].setCharacterSize(char_length);
		weights_text[i].setOrigin(char_length/4,char_length*0.625);
		weights_text[i].setPosition(2.3*width/5, pos_y);
		weights_text[i].setColor(sf::Color::Red);
		weights_text[i].setString("0");

		pos_x = pos_x - 50;

		inputs_text[i].setFont(font);
		inputs_text[i].setCharacterSize(char_length);
		inputs_text[i].setOrigin(char_length/4,char_length*0.625);
		inputs_text[i].setPosition(pos_x, pos_y);
		inputs_text[i].setColor(sf::Color::White);
		inputs_text[i].setString("0");
	}

	output_node.setRadius(rect_length/2);
	output_node.setOrigin(rect_length/2, rect_length/2);
	output_node.setPosition(3*width/5, height/2);
	output_node.setFillColor(sf::Color::Yellow);

	output_line[0] = sf::Vector2f(3*width/5, height/2);
	output_line[1] = sf::Vector2f(4*width/5, height/2);

	result_box.setSize(sf::Vector2f(rect_length, rect_length));
	result_box.setOrigin(rect_length/2, rect_length/2);
	result_box.setPosition(4*width/5, height/2);
	result_box.setFillColor(sf::Color::White);

	output_text.setFont(font);
	output_text.setCharacterSize(char_length);
	output_text.setOrigin(char_length/4,char_length*0.625);
	output_text.setPosition(4*width/5, height/2);
	output_text.setColor(sf::Color::Black);
	output_text.setString("0");

	status_text.setFont(font);
	status_text.setCharacterSize(char_length);
	status_text.setPosition(4*width/5, height/3);
	status_text.setColor(sf::Color::White);
	status_text.setString("0");

	condition_text.setFont(font);
	condition_text.setCharacterSize(char_length);
	condition_text.setPosition(4*width/5, 2*height/3);
	condition_text.setColor(sf::Color::White);
	condition_text.setString("0");
}

void NNetwork_field::draw()
{
	for(int i = 0; i < NUM_INPUTS; i++)
	{
		line_buffer[0] = weight_lines[i*2];
		line_buffer[1] = weight_lines[(i*2)+1];
		screen->draw(pixels[i]);
		screen->draw(line_buffer, 2, sf::Lines);
		screen->draw(weights_text[i]);
		screen->draw(inputs_text[i]);
		screen->draw(input_nodes[i]);
	}

	screen->draw(output_line, 2, sf::Lines);
	screen->draw(output_node);
	screen->draw(result_box);
	screen->draw(output_text);
	screen->draw(condition_text);
	screen->draw(status_text);
}

void NNetwork_field::update()
{
	string text_buffer;

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

	double input[4];
	int target = 0;

	for(int i = 0; i < NUM_INPUTS; i++)
	{
		text_buffer = std::to_string(network.weights[i]);
		weights_text[i].setString(text_buffer);

		if(dis(gen))
		{
			input[i] = 1;
			inputs_text[i].setString("1");
			pixels[i].setFillColor(sf::Color::White);
			target += 1;
		}
		else
		{
			input[i] = -1;
			inputs_text[i].setString("-1");
			pixels[i].setFillColor(sf::Color::Black);
			target += -1;
		}
	}

	if(target < 0)
		network.step(input, -1);
	else
		network.step(input, 1);

	output_text.setString(std::to_string(network.output));
	status_text.setString(network.status);
	condition_text.setString(network.condition);
}

void NNetwork_field::train()
{
	network.train();
}
