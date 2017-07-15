/*
converter file used to convert from letters to numbers and back
*/

int convert_char_to_int(char letter){
	return letter - 'a';
}

char convert_int_to_char(int letter){
	return letter + ('a');
}