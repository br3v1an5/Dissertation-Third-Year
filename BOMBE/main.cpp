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

#include "Enigma/main.cpp"
#include "Enigma/main.h"

char* BOMBEplaintext;
char* BOMBEciphertext;



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

	// Go through every single possible position, if it encodes the first one, then try the second with the next poistion
	// continue until all characters are encoded
	// given the plaintext is long enough
	// return the next set of settings

	// for every plugboard setup
	// for every choice of rotor
	// for every rotor displacement
	// for every reflector setup

	// if the plaintext is encrypted as the ciphertext then return the settings

	runEnigma(BOMBEplaintext);

	printf("%s\n", BOMBEciphertext);
	printf("%s\n", ciphertext);

	if (strcmp(BOMBEciphertext,ciphertext) == 0)
	{
		printf("It only works :D\n");
	}

	return 1;
}