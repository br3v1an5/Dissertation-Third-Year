/*
plugboard file
used to setup the plugboard from input settings
map from input to output
based on the input settings
*/

#include <iostream>

int mapping_forward[26];
int mapping_back[26];

void setup(int connections[26]){
	/*
	takes input from the main file
	in the form of an array that contains all the different
	connections and a 0 where the connection is unchanged
	*/

	int counter_0 = 0;
	// the counter to keep track of the index

	for (int x : connections) {
		// interate through the input list

		if (x == 0){
			// if the connection is not specified

			mapping_forward[counter_0] = counter_0;
			// it is set to itself in the forward mapping

			mapping_back[counter_0] = counter_0;
			// it is set to itself in the backward mapping
		}
		else{
			// if the connection is specified

			mapping_forward[counter_0] = x;
			// the forward connection is set

			mapping_back[x] = counter_0;
			// the backward connection is set
		}
		counter_0++;
		// the index is changed
	}
}

int plugboard_forward(int input){
	// the forward mapping
	return mapping_forward[input];
	// returns the letter that the input is mapped to
}

int plugboard_back(int input){
	// the backward mapping
	return mapping_back[input];
	// returns the letter that was mapped to the input
}