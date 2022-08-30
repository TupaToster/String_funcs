#include "protos.h"

/*!
    \brief Copies a string to heap
    \param src - string to copy
    \return ptr to an allocated memory

Returns a pointer to a newly allocated memory that contains a copy of a string
passed into it
*/
char* my_strdup (const char* src) {

    if (src == NULL) return NULL;
    
    char* return_val  = (char*) malloc (my_strlen (src));
    if (return_val == NULL) return NULL;
    unsigned int iter = 0;

    for (iter = 0; src[iter] != '\0'; iter++) {

        return_val[iter] = src[iter];
    }

    return_val[iter] = '\0';

    return return_val;
    
}