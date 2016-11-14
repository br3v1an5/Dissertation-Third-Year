/*
reflector file
used to setup the reflector from input settings
map from input to output
based on the input settings
*/

int reflector[26];


int setup_reflector(int connections[26]){
	/*
	takes input from the main file
	in the form of an array that contains all the different
	connections and a 0 where the connection is unchanged
	*/

	int counter_0 = 0;
	// set the counter to zero

	for (int i = 0; i<26; i++) {
		// interate through the input list
		int currentChar = connections[i];

		reflector[counter_0] = currentChar;
		// the connections are made
	
		counter_0++;
		// increment the counter
	}

	return 0;
}

int get_reflection(int index){
	/*
	take the input from the main file and return the corresponding letter
	*/

	return reflector[index];
}