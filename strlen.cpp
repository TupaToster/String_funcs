#include "protos.h"
/*!
    \brief Returns string length
    \param str - string to calculate len of
    \return -1 - if str is NULL
    \return anything >=0 - string's len

Calculates string length. Nothing more to say
*/
int my_strlen (const char* str) {
    
    if (str == NULL) return -1;

    int iter = 0;
    for (iter = 0; str[iter] != '\0'; iter++);
    
    return iter;
}