// (C) Poltorashka, Inc.
#include "protos.h"

void unit_test () {
	
	ungetc ('a', stdin);
	ungetc ('b', stdin);
	ungetc ('c', stdin);
	ungetc ('\n', stdin);
	char* s = (char*) malloc(1);
	assert (s != NULL);
	my_getline(&s);
	printf("%s", s);
	//if (strcmp("cba", s)) printf("Something wrong in my_getline \n");
	
}             