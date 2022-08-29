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

    char a[4] = "123";
    char b[4] = "456";
    printf ("%s %s\n", a, b);
    assert (my_strcpy (a, b) == OK);
    printf ("%s %s", a, b);

    
}