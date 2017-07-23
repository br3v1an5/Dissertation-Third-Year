/*
Brute force BOMBE file
used along with a cypher text and known plaintext
to work out the setting that are being used for the current 
encryption

to start:

g++ -std=c++11 main.cpp -o main
./main
*/



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "EnigmaClone/main.cpp"
#include "EnigmaClone/main.h"

char* BOMBEplaintext;
char* BOMBEciphertext;

int input_plugboard_data [] = {4,22,13,17,24,20,14,21,11,23,1,9,10,15,12,7,16,2,8,19,5,25,3,0,18,6};
int input_reflector_data [] = {25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
int input_rotors_data [] = {1,2,3};
int input_displacement_data [] = {0,0,0};



int main(int argc, char* argv[])
{
	/*
	this is the main file that will take in a plaintext then its corresponding ciphertext
	this is realistic as a good guess of the first word of the day would be 'weather'
	this was taken from weather reports and other words that were easy to guess was
	heil and hitler
	*/

	BOMBEplaintext = argv[1];
	BOMBEciphertext = argv[2];

	printf("%s\n", BOMBEplaintext);
	printf("%s\n", BOMBEciphertext);
	printf("\n");

	// Go through every single possible position, if it encodes the first one, then try the second with the next poistion
	// continue until all characters are encoded
	// given the plaintext is long enough
	// return the next set of settings

	// for every plugboard setup
	// for every choice of rotor
	// for every rotor displacement
	// for every reflector setup

	// if the plaintext is encrypted as the ciphertext then return the settings

	// how to be able to run enigma with command line parameters????
	// first make it run from here

	for (int rotor1 = 1; rotor1 < 9; rotor1++)
	{
		for (int rotor2 = 1; rotor2 < 9; rotor2++)
		{
			for (int rotor3 = 1; rotor3 < 9; rotor3++)
			{
				if (rotor1 != rotor2 and rotor1 != rotor3 and rotor2 != rotor3)
				{
					input_rotors_data[0] = rotor1;
					input_rotors_data[1] = rotor2;
					input_rotors_data[2] = rotor3;

					// MAKE SURE THAT THE ROTOR DATA IS CORRECT

					for (int x = 0; x < 26; ++x)
					{
						for (int y = 0; y < 26; ++y)
						{
							for (int z = 0; z < 26; ++z)
							{
								input_displacement_data[0] = z;
								input_displacement_data[1] = y;
								input_displacement_data[2] = x;

								// MAKE SURE THAT THE DISPLACEMENT DATA IS CORRECT

								enigma(BOMBEplaintext, BOMBEciphertext, input_plugboard_data, input_reflector_data, input_rotors_data, input_displacement_data);

								if (matches)
								{
									for (int i = 0; i < 26; ++i)
									{
										printf("%d,", input_plugboard_data[i]);
									}
									printf("\n");
									for (int i = 0; i < 26; ++i)
									{
										printf("%d,", input_reflector_data[i]);
									}
									printf("\n");
									for (int i = 0; i < 3; ++i)
									{
										printf("%d,", input_rotors_data[i]);
									}
									printf("\n");
									for (int i = 0; i < 3; ++i)
									{
										printf("%d,", input_displacement_data[i]);
									}
									printf("\n");

									return 1;
								}

								//printf("\n");

							}
						}
					}
				}
			}
		}
	}

	return 1;
}