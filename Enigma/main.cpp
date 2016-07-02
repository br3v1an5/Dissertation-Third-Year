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

#include <iostream>

int main()
{
    std::cout << "Hello world!" << std::endl;

    setup();

    int value = add_one(5);

    using namespace std;
    cout << "The value back is " << value << endl;
}