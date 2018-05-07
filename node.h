#include <random>

// Node-Based Feed-Forward Perceptron Demonstration
// Information flow is unidirectional, no multithreading required.

#ifndef NODE_H
#define NODE_H

class Node
{
	public:
	Node();
	void learn(double error);
	void input(double input);
	void transmit(Node &output_node);
	double sum();
	double weight;
	double learn_weight;
	private:
	void init();
	double entry;
	double output;
};

#endif
