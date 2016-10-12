/*
reflector file
used to setup the reflector from input settings
map from input to output
based on the input settings
*/

int reflector[26];


void setup(int connections[26]){
	/*
	takes input from the main file
	in the form of an array that contains all the different
	connections and a 0 where the connection is unchanged
	*/

	counter_0 = 0;
	// set the counter to zero

	for (int x : connections) {
		// interate through the input list

		reflector[counter_0] = x;
		// the connections are made
	
		counter_0++;
		// increment the counter
	}
}

int get_reflection(int index){
	/*
	take the input from the main file and return the corresponding letter
	*/

	return reflector[index];
}