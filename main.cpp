// (C) Poltorashka, Inc.
#include "protos.h"

/*!
	\file
Main body that will present some opportunities to test 
functions of a program to a user, but for now it's just eh 
*/

int main (int argc, char* argv[]){
	
	if (argc > 1 and strcmp (argv[1], "--test") == 0){
		unit_test ();
		return 0; 	
	}

	printf ("Input string to apply stuff to: ");
	
	char* s = NULL;
	s = (char*) malloc (1);
	if (s == NULL) return -1;	
	if (my_getline (&s, stdin) == MEM_ERR) return -1;

	printf("%s", s);
}	
