// (C) Poltorashka, Inc.
#include <TXlib.h>

enum action_status {
	OK      = 1,
	MEM_ERR = 0
};

action_status my_getline (char** string_to_input_to);

unsigned int string_size (const char* string_to_measure);

action_status my_strncpy (char** from, char** to, unsigned int n);

action_status my_strcpy (char* from, char* to);

action_status my_smart_strcpy (char** from, char ** to);

void unit_test ();