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

int enigma(char* input, int inputPlugboard[26], int inputReflector[26], int inputRotors[3], int inputDisplacement[3])
{
	for (int i = 0; i < 26; ++i)
	{
		plugboard_data[i] = inputPlugboard[i];
		reflector_data[i] = inputReflector[i];
	}

	for (int i = 0; i < 3; ++i)
	{
		rotors_data[i] = inputRotors[i];
		displacement_data[i] = inputDisplacement[i];
	}

	plaintext = input;
	ciphertext = input;
	printf("Plaintext:	");
	printf("%s\n", plaintext);
	printf("Ciphertext:	");
	printf("%s\n", ciphertext);

	setup_plugboard(plugboard_data);
	// setup the plugboard

	setup_reflector(reflector_data);
	// setup the reflector

	int toEncrypt;

	for (int i=0; i<strlen(plaintext); i++){
		//printf("%c\n", plaintext[i]);

		toEncrypt =  convert_char_to_int(plaintext[i]);
		// convert the chars to corresponding ints
		//printf("Char to Int: %d\n", toEncrypt);

		toEncrypt = plugboard_forward(toEncrypt);
		// use the plugboard
		//printf("After the Plugboard: %d\n", toEncrypt);

		// store the first rotor
		// used the first rotor
		toEncrypt = rotors[
			rotors_data[0] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		//printf("After the first rotor: %d\n", toEncrypt);

		// store the second rotor
		// use the second rotor
		toEncrypt = rotors[
			rotors_data[1] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		//printf("After the second rotor: %d\n", toEncrypt);

		// store the third rotor
		// use the thrid rotor
		toEncrypt = rotors[
			rotors_data[2] - 1][
			(toEncrypt + displacement_data[0]) % 26];
		//printf("After the third rotor: %d\n", toEncrypt);

		// use the reflector
		toEncrypt = get_reflection(toEncrypt);
		//printf("After reflection: %d\n", toEncrypt);

		// back through the third rotor
		toEncrypt = get_rotor_reverse(rotors_data[2] - 1, toEncrypt);
		//printf("After the third rotor: %d\n", toEncrypt);

		// back through the second rotor
		toEncrypt = get_rotor_reverse(rotors_data[1] - 1, toEncrypt);
		//printf("After the second rotor: %d\n", toEncrypt);

		// back through the first rotor
		toEncrypt = get_rotor_reverse(rotors_data[0] - 1, toEncrypt);
		//printf("After the first rotor: %d\n", toEncrypt);

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
		//printf("After the plugboard: %d\n", toEncrypt);

		ciphertext[i] = convert_int_to_char(toEncrypt);
		// convert the fully encrypted int back to a char

		//printf("Done: %c\n", ciphertext[i]);
		// print the encrypted letter
	}

	printf("Plaintext:	");
	printf("%s\n", input);
	printf("Ciphertext:	");
	printf("%s\n", ciphertext);

	return 1;
}