// (C) Poltorashka, Inc.
#include "protos.h"

int main (int argc, char* argv[]){
	
	if (argc > 1 and strcmp (argv[1], "--test") == 0){
		unit_test ();
		return 0;	 	
	}

	printf ("Input string to apply stuff to: ");
	
	char* s = NULL;
	s = (char*) malloc (1);
	if (s == NULL) return -1;	

	if (my_getline (&s) == MEM_LIM) return -1;

	printf("%s", s);
}	
