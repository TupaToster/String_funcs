#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



/*!
    Displays status of action that involves changing memory or reading it
*/
enum action_status{
    OK      = 0,  ///< Everything ok
    MEM_ERR = -1, ///< Memory error, i.e. something wrong with pointers
    OVERFL  = 1  ///< Overflow error, i.e. not enough memory
};

action_status my_fputs (const char* out_str, FILE* stream);

int my_strlen (const char* str);

action_status my_strcpy (char* const from, char* const to);

action_status my_strncpy (char* const from, char* const to, const unsigned int n);

action_status my_smart_strcpy (const char* from, char** to);

action_status my_strcat (const char* from, char** to);