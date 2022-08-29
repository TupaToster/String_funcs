#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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