// (C) Poltorashka, Inc.
#include <TXlib.h>

#define ASRT(cnd) if(!(cnd)) printf("\n"					 \
									"Assertion failed: %s\n"\
									"in file %s\n"			 \
                					"function %s\n"			 \
                					"line %d\n",		     \
    				  #cnd, __FILE__, __PRETTY_FUNCTION__, __LINE__);


enum action_status {
	OK      = 0,
	MEM_ERR = -1,
	OVERFL = 1
};

action_status my_getline (char** const string_to_input_to, FILE* input);

unsigned int string_size (const char* string_to_measure);

action_status my_strncpy (char* const from, char* const to, unsigned int n);

action_status my_strcpy (char* const from, char* const to);

action_status my_smart_strcpy (char** const from, char** const to);

int my_fputs (const char* out_str, const FILE* out_fstream);

void unit_test ();