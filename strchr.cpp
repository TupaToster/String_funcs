#include "protos.h"

/*!
    \brief Finds a char
    \param src - string to search in
    \param ch - char to search for
    \return ptr to a char in string
    \return NULL if there is no char in string or no string

Finds a set char in a set string and returns a ptr to char in the string
*/

char* my_strchr (char* const src, const char ch) {

    if (src == NULL) return NULL;

    char* return_val = src;

    while (return_val != '\0' and *return_val != ch) return_val++;

    if (*return_val == ch) return return_val;
    else return NULL; 

}