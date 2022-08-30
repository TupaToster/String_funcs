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

    if (from == NULL or to == NULL) return MEM_ERR;
    
    unsigned int iter = 0;

    for (iter = 0; from[iter] != '\0' and iter < n; iter++) to[iter] = from[iter];

    to[iter] = '\0';

    if (iter == n and from[iter] == '\0') return OK;
    if (iter == n and from[iter] != '\0') return OVERFL;

    return OK;    
}

/*!
    \brief Super smart strcpy
    \param from - pointer to a string to copy from
    \param to - pointer to a string to copy to
    \return OK - if successfully copied
    \return MEM_ERR - if some pointers are NULL
    \return OVERFL - if pc runs out of storage space

Smart ctrcpy rellocates "to" string for it to fit exactly as many chars as "from"
*/
action_status my_smart_strcpy (const char* from, char** to) {

    if (from == NULL or to == NULL) return MEM_ERR;

    char* temp = (char*) malloc (my_strlen(from) + 1);
    if (temp == NULL) return OVERFL;
    *to = temp;

    unsigned int iter = 0;
    for (iter = 0; from[iter] != '\0'; iter++) (*to)[iter] = from[iter];
    (*to)[iter] = '\0';

    return OK;
}

