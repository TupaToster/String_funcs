// (C) Poltorashka, Inc.
#include <TXlib.h>


enum input_status {
	OK      = 1,
	MEM_LIM = 0
};


input_status my_getline (char** string_to_input_to);

unsigned int string_size (const char* string_to_measure);

void unit_test ();