/*
plugboard file
used to setup the plugboard from input settings
map from input to output
based on the input settings
*/

#include <iostream>

void setup(){
	std::cout << "this is in setup" << std::endl;
}

int add_one(int in){
	return in + 1;
}

int plugboard_forward(){
	return 1;
}

int plugboard_back(){
	return 1;
}