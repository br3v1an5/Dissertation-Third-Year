# Dissertation-Third-Year
My third year project, BOMBE and Enigma simulation
Engima set up

The main file will have each component included within it
- plugboard
- 5 different rotors
- 2 different reflectors

these will be set up in the "setup" method, this will pass to all files the set up information that has been passed to it
my calling the main method which will run the set up and then run the encode/decode

main()
	- setup()
		- plugboard_setup()
		- refector_select()
		- refector_setup()
		- select_rotors()
		- set_rotor_position_left()
		- set_rotor_position_centre()
		- set_rotor_position_right()
		- get_upper()
		- set_rotor_upper_left()
		- set_rotor_upper_centre()
		- set_rotor_upper_right()
		- get_message_setting()
	- encode()
		- plugboard()
		- right_rotor()
		- middle_rotor()
		- left_rotor()
		- refection()
		- left_rotor() (reverse?)
		- middle_rotor() (reverse?)
		- right_rotor() (reverse?)
		- plugboard_reverse()
		- return

plugboard
- setup()
takes in the settings that will then be used to set the plugboard values
- plugboard_forward()
will map forward
- plugboard_backward()
will map on the return

refelector
- setup()
takes the settings that will map input to output and sets it up
- reflector()
takes input and maps to corresponding output

rotor1, rotor2, rotor3, rotor4, rotor5
- setup()
takes intial position and initial upward and sets up rotor
- take_input_forward()
takes a number (which has a corresponding letter) and outputs its corresponding value
- take_input_backwards()
takes a number and outputs the corresponding value for the return from the reflector
- to_rotate()
returns a boolean that dictates if the next rotor should rotate
- rotate()
rotates the rotor one place
