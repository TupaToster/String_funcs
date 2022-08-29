#include "protos.h"


/*!
    \brief Concatenates strings
    \param from - string to concat
    \param to - ptr to string to concat to
    \return OK if allright
    \return MEM_ERR if one of ptrs is NULL
    \return OVERFL if pc is out of mem

Concatenates two strings into the "to" one
*/
action_status my_strcat (const char* from, char** to) {

    if (from == NULL or to == NULL or *to == NULL) return MEM_ERR;

    int to_len = my_strlen (*to);

    char* temp = (char*) malloc (to_len + my_strlen (from) + 1);
    if (temp == NULL) return OVERFL;
    
    unsigned int iter = 0;
    for (iter = 0; (*to)[iter] != '\0'; iter++) temp[iter] = (*to)[iter];

    for (; from[iter - to_len] != '\0'; iter++) temp[iter] = from[iter - to_len];

    temp[iter] = '\0';
    *to = temp;

    return OK;
}

/*!
    \brief Concatenates two strings with limit
    \param from - string to concatenate from
    \param to - string to concatenate to
    \param n - max amount if symbols to concat from "from"
    \return OK - all fine
    \return MEM_ERR - one or more pts are NULL
    \return OVERFL - not enough memory

Concats two strings, but adds not more then n symbols from "from"
*/
action_status my_strncat (const char* from, char** to, unsigned int n) {

    if (from == NULL or to == NULL or *to == NULL) return MEM_ERR;

    unsigned int to_len = my_strlen (*to);
    char* temp = (char*) malloc (to_len + (my_strlen(from) < n ? my_strlen(from) : n) + 1);
    if (temp == NULL) return OVERFL;
    
    unsigned int iter = 0;
    for (iter = 0; (*to)[iter] != '\0'; iter++) temp[iter] = (*to)[iter];
    
    for (; from[iter - to_len] != '\0' and iter - to_len < n; iter++) 
        temp[iter] = from[iter - to_len];
    
    temp[iter] = '\0';

    (*to) = temp;
    return OK; 
}