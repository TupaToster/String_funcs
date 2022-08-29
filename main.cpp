#include "protos.h"


/*!
    \brief Will contain some ways to interact with functions
    \param argc - count of com line args
    \param argv - array of com line args
    \return 0 - if OK
*/
int main (int argc, char* argv[]) {

    if (argc > 1 and strcmp (argv[1], "--test")) {

    }

    char* a = (char*) calloc (10, 1);
    char* b = (char*) calloc (2, 1);
    a[0] = '1';
    a[1] = '2';
    a[2] = '3';
    a[3] = '\0';
    b[0] = '1';
    b[1] = '\0';
    printf ("%s %s\n", a, b);
    assert (my_smart_strcpy (&a, &b) == OK);
    printf ("%s %s", a, b);
}