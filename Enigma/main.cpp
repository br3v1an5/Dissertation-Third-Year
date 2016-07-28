/*
Main enigma file
used to coordinate all others
used to encode and decode cyphertext

to start:

g++ main.cpp -o main
./main
*/

#include "plugboard.cpp"
#include "reflector.cpp"
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

int main()
{
    std::cout << "Hello world!" << std::end;
}