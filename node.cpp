#include "node.h"

// Node-Based Feed-Forward Perceptron Demonstration
// Information flow is unidirectional, no multithreading required.

Node::Node()
{
	learn_weight = 2.0;
	output = 0.0;
	entry = 0.0;
	init();
}

void Node::learn(double error)
{
	weight += learn_weight * error * entry;
}

void Node::input(double input)
{
	output += input;
	entry = input;
}

void Node::transmit(Node &output_node)
{
	output = output * weight;
	output_node.input(output);
	output = 0.0;
}

double Node::sum()
{
	double temp = output;
	output = 0.0;
	return temp;
}

void Node::init()
{
	//Generate random weight between -1 and 1
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 0.0);
    weight = dis(gen);
}
