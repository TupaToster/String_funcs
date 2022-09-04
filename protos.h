#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//Uncomment line below in case of emergency
//#include <bits\stdc++.h>



/*!
    Displays status of action that involves changing memory or reading it
*/
enum action_status{
    OK      = 0,  ///< Everything ok
    MEM_ERR = -1, ///< Memory error, i.e. something wrong with pointers
    OVERFL  = 1  ///< Overflow error, i.e. not enough memory
};

/*!
Assert but without stopping the program
*/
#define ASRT(cnd) if(!(cnd)) printf("\n"					 \
									"Assertion failed: %s \n"\
									"in file %s\n"			 \
                					"function %s\n"			 \
                					"line %d \n",		     \
    				  #cnd, __FILE__, __PRETTY_FUNCTION__, __LINE__);

action_status my_fputs (const char* out_str, FILE* stream);

unsigned int my_strlen (const char* str);

action_status my_strcpy (char* const from, char* const to);

action_status my_strncpy (char* const from, char* const to, const unsigned int n);

action_status my_smart_strcpy (const char* from, char** to);

action_status my_strcat (const char* from, char** to);

action_status my_strncat (const char* from, char** to, const unsigned int n);

action_status my_fgets (char** to, FILE* stream);

char* my_strdup (const char* src);

char* my_strchr (char* const src, const char ch);

void unit_test ();

void mergesort_str (char** l, char** r);

void mergesort_str_inside (char** l, char** r, char** temp);