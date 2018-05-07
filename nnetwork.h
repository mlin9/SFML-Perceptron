#include "node.h"
#include <iostream>
#include <string>

#ifndef ANN_H
#define ANN_H

// Node-Based Feed-Forward Perceptron Demonstration
// Information flow is unidirectional, no multithreading required.

#define NUM_INPUTS 4

using namespace std;

class NNetwork
{
	public:
	NNetwork();
	~NNetwork();
	void train();
	void step(double *input, int target);
	void set_learn_weight(double input);
	double **training_data;
	double weights[NUM_INPUTS];
	int output;
	string status;
	string condition;
	private:
	Node input_layer[NUM_INPUTS];
	Node output_node;
};

#endif
