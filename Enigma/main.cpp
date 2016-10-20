/*
Main enigma file
used to coordinate all others
used to encode and decode cyphertext

to start:

g++ -std=c++11 main.cpp -o main
./main
*/

/*
#include "plugboard.cpp"
#include "reflector.cpp"
*/
#include "rotor_one.cpp"
#include "rotor_two.cpp"
#include "rotor_three.cpp"
#include "rotor_four.cpp"
#include "rotor_five.cpp"
#include "rotor_six.cpp"
#include "rotor_seven.cpp"
#include "rotor_eight.cpp"
#include "converter.cpp"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int setup(char* file_name)
{
	// take in a .txt file as a parameter that contains all the setup information and all the plaintext

	int input_data[58];
	int plugboard_data[26];
	int reflector_data[26];
	int rotors_data[3];
	int displacement_data[3];

	ifstream file(file_name);
	if(file.is_open())
	{
		for(int i = 0; i < 58; ++i)
		{
			file >> input_data[i];
		}
	}

	else cout << "Unable to open file";

	printf("Input:");
	for (int x=0; x<57; x++)
	{
		printf(" %i,", input_data[x]);
	}
	printf(" %i\n", input_data[57]);

	for (int x=0; x<58; x++)
	{
		if(x<26)
		{
			plugboard_data[x] = input_data[x];
		}
		if(24<=x && x<52)
		{
			reflector_data[(x-26)] = input_data[x];
		}
		if(50<=x && x<55)
		{
			rotors_data[(x-52)] = input_data[x];
		}
		if(53<x)
		{
		displacement_data[(x-55)] = input_data[x];
		}
	}

	printf("Plugboard:");
	for (int x=0; x<25; x++)
	{
		printf(" %i,", plugboard_data[x]);
	}
	printf(" %i\n", plugboard_data[25]);

	printf("Reflector:");
	for (int x=0; x<25; x++)
	{
		printf(" %i,", reflector_data[x]);
	}
	printf(" %i\n", reflector_data[25]);

	printf("Rotors:");
	for (int x=0; x<2; x++)
	{
		printf(" %i,", rotors_data[x]);
	}
	printf(" %i\n", rotors_data[2]);

	printf("Displacement:");
	for (int x=0; x<2; x++)
	{
		printf(" %i,", displacement_data[x]);
	}
	printf(" %i\n", displacement_data[2]);

	/*
	// take input for which rotors to use
	printf("Rotors: %i, %i, %i\n", rotors[0], rotors[1], rotors[2]);

	// take input for the displacement of each rotor from its start position
	printf("Displacement of rotors: %i, %i, %i\n", displacement[0], displacement[1], displacement[2]);
	*/

	return 1;
}

int main(int argc, char* argv[]) // or char** argv 
{
	// ask for the name of a .txt file
	// pass this name to the setup function
	setup(argv[1]);
	return 1;
}