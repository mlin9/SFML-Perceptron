#include "nnetwork.h"

NNetwork::NNetwork()
{

}

NNetwork::~NNetwork()
{
	for(int i = 0; i < 16; i++)
		delete[] training_data[i];
	delete[] training_data;
}

void NNetwork::train()
{
	training_data = new double*[16];
	for(int i = 0; i < 16; i++)
		training_data[i] = new double[4];
	
	int data_index = 0;
	double data_string[] = {-1,-1,-1,-1,
							-1,-1,-1, 1,
							-1,-1, 1,-1,
							-1,-1, 1, 1,
							-1, 1,-1,-1,
							-1, 1,-1, 1,
							-1, 1, 1,-1,
							-1, 1, 1, 1,
							 1,-1,-1,-1,
							 1,-1,-1, 1,
							 1,-1, 1,-1,
							 1,-1, 1, 1,
							 1, 1,-1,-1,
							 1, 1,-1, 1,
							 1, 1, 1,-1,
							 1, 1, 1, 1};
	double targets[] = {0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
	
	
	for(int row = 0; row < 16; row++)
	{
		for(int col = 0; col < 4; col++)
		{
			training_data[row][col] = data_string[data_index];
			data_index++;
		}
		
		step(training_data[row], targets[row]);
	}
	
}

void NNetwork::step(double *input, int target)
{
	int result = 1;
	status = "bright";
	condition = "correct";
	
	for(int i = 0; i < NUM_INPUTS; i++)
	{
		weights[i] = input_layer[i].weight;
	}
	
	for(int i = 0; i < NUM_INPUTS; i++)
	{
		input_layer[i].input(input[i]);
		input_layer[i].transmit(output_node);
	}
	
	output = output_node.sum();
	
	if(output < -0.1)
	{
		result = -1;
		status = "dark";
	}
	
	int error = target - result;
	
	for(int i = 0; i < NUM_INPUTS; i++)
	{
		input_layer[i].learn(error);
	}
	
	output = result;
	
	if(error != 0)
		condition = "incorrect";
}

void NNetwork::set_learn_weight(double input)
{
	for(int i = 0; i < NUM_INPUTS; i++)
	{
		input_layer[i].learn_weight = input;
	}
}
