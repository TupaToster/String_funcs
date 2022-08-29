#include "protos.h"

/*!
    \brief Simply copies one string into other
    \param from - string to copy from
    \param to - string to copy to
    \return OK - if copied
    \return MEM_ERR - if one or more parameters are NULL

Simple cstcpy function that does not care about any possible damage it may make
It is trying hard not to cause any seg fault
*/

action_status my_strcpy (char* const from, char* const to) {

    if (from == NULL or to == NULL) return MEM_ERR;

    unsigned int iter = 0;
    for (iter = 0; from[iter] != '\0'; iter++) {

        to[iter] = from[iter];
    }

    to[iter] = '\0';

    return OK;
}

/*!
    \brief A bit more complex copy func
    \param from - string to copy from
    \param to - string to copy to
    \param n - number of chars to copy
    \return OK if all ok
    \return MEM_ERR if one or more ptrs 
    \return OVERFL if pc ran out of free mem

Function to copy not more than n chars
also can kinda cause seg fault
*/
action_status my_strncpy (char* const from, char* const to, unsigned int n) {

    if (from == NULL or to == NULL) return OVERFL;
    
    unsigned int iter = 0;

    for (iter = 0; from[iter] != '\0' and iter < n; iter++) to[iter] = from[iter];

    to[iter] = '\0';

    if (iter == n and from[iter] == '\0') return OK;
    if (iter == n and from[iter] != '\0') return OVERFL;
    
    return OK;    
}