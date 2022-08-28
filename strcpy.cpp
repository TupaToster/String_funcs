// (C) Poltorashka, Inc.
#include "protos.h"

/*!
    \brief A simply strcpy function
    \param char* from - string to copy from
    \param char* to   - string to copy to
    \return OK in all cases except when MEM_LIM
    \return MEM_ERR if one of the pointers is NULL

    A simple function that copies c-string from to c-string to without minding the sizes of both
    Actually may cause segmentation fault if used wrong
*/


action_status my_strcpy (char* from, char* to) {

    if (from == NULL or to == NULL) return MEM_ERR;

    unsigned int iter = 0;
    for (iter = 0; from[iter] != '\0'; iter++) {

        to[iter] = from[iter];
    }
    
    to[iter + 1] = '\0';

    return OK;
}
