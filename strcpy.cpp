// (C) Poltorashka, Inc.
#include "protos.h"

/*!
    \file
This file contains family of my_strcpy, my_strncpy, my_smart_strcpy
*/

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

/*!
    \brief The smartest copy paste of all three
    \param from - c-string to copy from
    \param to   - c-string to copy to
    \return OK - if all ok and pc had enough memory
    \return MEM_ERR - one of parameters is either NULL or points to NULL
    \return OVERFL - if pc does not have enough memory to fully copy the string

This thing also copies from "from" to "to" but with another twist - 
it actually allocates right enough memory for all "from" to fit in "to".

In case if this is impossible returns OVERFL and keeps the strings' contents
*/
action_status my_smart_strcpy (char** from, char** to) {

    if (from  == NULL or
        to    == NULL or
        *from == NULL or
        *to   == NULL) {
            
        return MEM_ERR;
    }

    char* temp = NULL ///< Temporary pointer to store allocated memory's adress

    temp = malloc (*to, string_size (*from));
    if(temp == NULL) return OVERFL;
    else             *str = temp;

    unsigned int iter = 0;
    for (iter = 0; from[iter] != '\0'; iter++) {

        *to[iter] = *from[iter];
    }
    *to[iter] = '\0';

    return OK;
}