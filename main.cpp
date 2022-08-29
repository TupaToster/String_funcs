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
    
    char* a = "a";
    char* b = "abcdef";
    assert (my_smart_strcpy (b, &a) == OK);
    printf("%s", a);
    return 0;
}