// (C) Poltorashka, Inc.
#include "protos.h"

/*!
    \brief A simply strcpy function
    \param from - string to copy from
    \param to   - string to copy to
    \return OK in all cases except when MEM_LIM
    \return MEM_ERR if one of the pointers is NULL

    A simple function that copies  "from" to "to" without minding the sizes of both
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

/*!
    \brief A less simple function strncpy
    \param from - c-string to copy from
    \param to   - c-string to copy to
    \param n    - max amount of chars (including \0) to be copied
    \return OK - if everything is ok
    \return OVERFL - if not all chars were copied
    \return MEM_ERR - if "to" or "from" is NULL

This thing copies from "from" to "to" but with a twist - 
max amount of copied chars (with \0) is "n"

Still may cause segmentation fault if used wrong but more rare
*/

action_status my_strncpy (char* from, char* to, unsinged int n) {

    if (from == NULL or to == NULL) return MEM_ERR;

    unsigned int iter = 0;
    for (iter = 0; from[iter] != '\0' and iter < n - 1; iter++) {

        to[iter] = from[iter];
    }
    
    to[iter] = '\0';
    
    if(iter == n-1) return OVERFL;
    else return OK;
}