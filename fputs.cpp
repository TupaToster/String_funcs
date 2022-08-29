#include "protos.h"


/*!
    \brief Simple file output function
    \param out_str - const string to output
    \param stream  - output stream
    \return OK - if everything went cool
    \return MEM_ERR - if one of parametres is NULL
    \return OVERFL - if it's impossible to put char into file

Prints a string into a file and doesn't mind sizes of both, also can't abort program
*/
action_status my_fputs (const char* out_str, FILE* stream) {

    if (out_str == NULL or stream == NULL) return MEM_ERR;

    for (int iter = 0; out_str[iter] != '\0'; iter++) {

        if(fputc (out_str[iter], stream) == EOF) return OVERFL;
    }

    return OK;
}