/*
Main enigma file
used to coordinate all others
used to encode and decode cyphertext

to start:

g++ -std=c++11 main.cpp -o main
./main
*/


#include "plugboard.cpp"
#include "plugboard.h"

#include "reflector.cpp"
#include "reflector.h"

#include "rotors.cpp"

#include "converter.cpp"
#include "converter.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int input_data[58];
int plugboard_data[26];
int reflector_data[26];
int rotors_data[3];
int displacement_data[3];
char* plaintext;
char* ciphertext;

/*
char* validate_input(char* input){
	char* output = boost::erase_all(input, "1");
}
*/

int setup()
{
	// the text file being used for setup has a hardcoded name

	ifstream file("setupFile.txt");
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

	printf("Rotor Details:\n");
	for (int x=0; x<3; x++)
	{
		for (int y=0; y<25; y++)
		{
			printf(" %i,	", rotors[x][y]);
		}
		printf(" %i\n", rotors[x][25]);
	}

	printf("Displacement:");
	for (int x=0; x<2; x++)
	{
		printf(" %i,", displacement_data[x]);
	}
	printf(" %i\n", displacement_data[2]);
	
	

	return 1;
}

int main(int argc, char* argv[])
{
	// ask for the name of a .txt file
	// pass this name to the setup function
	setup();

	plaintext = argv[1];
	ciphertext = argv[1];
	printf("Plaintext: ");
	printf("%s\n", plaintext);

	setup_plugboard(plugboard_data);
	// setup the plugboard

	setup_reflector(reflector_data);
	// setup the reflector

	int toEncrypt;

	for (int i=0; i<strlen(plaintext); i++){
		printf("%c\n", plaintext[i]);

		toEncrypt =  convert_char_to_int(plaintext[i]);
		// convert the chars to corresponding ints
		printf("Char to Int: %d\n", toEncrypt);

		toEncrypt = plugboard_forward(toEncrypt);
		// use the plugboard
		printf("After the Plugboard: %d\n", toEncrypt);

		// store the first rotor
		// used the first rotor
		toEncrypt = rotors[
			rotors_data[0] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		printf("After the first rotor: %d\n", toEncrypt);

		// store the second rotor
		// use the second rotor
		toEncrypt = rotors[
			rotors_data[1] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		printf("After the second rotor: %d\n", toEncrypt);

		// store the third rotor
		// use the thrid rotor
		toEncrypt = rotors[
			rotors_data[2] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		printf("After the third rotor: %d\n", toEncrypt);

		// use the reflector
		toEncrypt = get_reflection(toEncrypt);
		printf("After reflection: %d\n", toEncrypt);

		// back through the third rotor
		toEncrypt = get_rotor_reverse(rotors_data[2] - 1, toEncrypt);
		printf("After the third rotor: %d\n", toEncrypt);

		// back through the second rotor
		toEncrypt = get_rotor_reverse(rotors_data[1] - 1, toEncrypt);
		printf("After the second rotor: %d\n", toEncrypt);

		// back through the first rotor
		toEncrypt = get_rotor_reverse(rotors_data[0] - 1, toEncrypt);
		printf("After the first rotor: %d\n", toEncrypt);

		// do turnover for all rotors

		displacement_data[0] = displacement_data[0] + 1;
		// turn the first rotor every time that it is used

		if (displacement_data[0] == turnovers[rotors_data[0] - 1][0] || displacement_data[0] == turnovers[rotors_data[0] - 1][1] || displacement_data[0] == 25){
			// if the first rotor reaches one if its turnover points then step the second rotor
			displacement_data[1] = displacement_data[1] + 1;

			if (displacement_data[1] == turnovers[rotors_data[1] - 1][0] || displacement_data[1] == turnovers[rotors_data[1] - 1][1] || displacement_data[1] == 25){
				// if the second rotor reaches one of its turnover points then step the thrid rotor
				displacement_data[2] = displacement_data[2] + 1;
			}
		}

		displacement_data[0] = displacement_data[0] % 26;
		displacement_data[1] = displacement_data[1] % 26;
		displacement_data[2] = displacement_data[2] % 26;

		// back through the plugboard
		toEncrypt = plugboard_back(toEncrypt);
		printf("After the plugboard: %d\n", toEncrypt);

		ciphertext[i] = convert_int_to_char(toEncrypt);
		// convert the fully encrypted int back to a char

		//printf("Done: %c\n", ciphertext[i]);
		// print the encrypted letter
	}

	printf("Ciphertext: ");
	printf("%s\n", ciphertext);

	ofstream setupFileOut;
  	setupFileOut.open ("setup.txt");

  	setupFileOut << "[";
  	for (int x=0; x<25; x++)
  	{
  		setupFileOut << plugboard_data[x];
  		setupFileOut << ",";
  	}
  	setupFileOut << plugboard_data[25];
  	setupFileOut << "]\n";

  	setupFileOut << "[";
  	for (int x=0; x<25; x++)
  	{
  		setupFileOut << reflector_data[x];
  		setupFileOut << ",";
  	}
  	setupFileOut << reflector_data[25];
  	setupFileOut << "]\n";

  	setupFileOut << "[";
  	for (int x=0; x<2; x++)
  	{
  		setupFileOut << rotors_data[x];
  		setupFileOut << ",";
  	}
  	setupFileOut << rotors_data[2];
  	setupFileOut << "]\n";

  	setupFileOut << "[";
  	for (int x=0; x<2; x++)
  	{
  		setupFileOut << displacement_data[x];
  		setupFileOut << ",";
  	}
  	setupFileOut << displacement_data[2];
  	setupFileOut << "]\n";

  	setupFileOut.close();

	return 1;
}