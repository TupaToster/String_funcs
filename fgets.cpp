#include "protos.h"

/*!
    \brief Gets string from input file
    \param to - string to read to
    \param stream - filestream to read rom
    \return OK - all fine
    \return MEM_ERR - one or more pts are NULL(ded)
    \return OVERFL - pc ran out of storage space (also erases everything from "to")

Reads string from file dynamically changing string's length
may have a bit unefficient memory management
*/
action_status my_fgets (char** to, FILE* stream) {
    
    if (to == NULL or stream == NULL) return MEM_ERR;

    unsigned int str_size = my_strlen (*to);
    unsigned int iter     = 0;
    int input_ch          = fgetc (stream);

    if (*to == NULL) {
        str_size = 1;
        *to = (char*) malloc (1);
        if (*to == NULL) return OVERFL;
    }

    for (iter = 0; input_ch != (int) '\n' and input_ch != EOF; iter++) {

        if (iter == str_size) {
            
            str_size *= 2;
            *to = (char*) realloc (*to, str_size);
            if (*to == NULL) return OVERFL;
        }

        (*to)[iter] = (char) input_ch;
        input_ch = fgetc (stream);
    }

    *to = (char*) realloc (*to, iter);
    if (*to == NULL) return OVERFL;
    (*to)[iter] = '\0';

    return OK;
}