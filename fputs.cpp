// (C) Poltorashka, Inc.
#include "protos.h";

/*!
    \brief Prints out a c-string
    \param out_str - c-string to print
    \param out_fstream - pointer to an output file stream
    \return OK - everything printed
    \return MEM_ERR - out_str == NULL or out_fstream == NULL
    \return OVERFL - mistake in fputc (i guess that happens if the file runs out of free space)

Prints out a c-string and tries not to abort the program if any error occurs.
For example: if there is nothing or nowhere to output, then the program will
just return MEM_ERR. It's based on fputc because i just felt like it should be.
*/

action_status my_fputc (const char* out_str, const FILE* out_fstream) {

    if (out_str == NULL or out_fstream == NULL) return MEM_ERR;

    for (unsigned int iter = 0; out_str[iter] != '\0'; iter++) {
        
        if (fputc ((int) str[iter], out_fstream) == EOF) return OVERFL;       
    }

    return OK;
}