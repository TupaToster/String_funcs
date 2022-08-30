#include "protos.h"


/*!
    \brief Will contain some ways to interact with functions
    \param argc - count of com line args
    \param argv - array of com line args
    \return 0 - if OK

Now will hold a program that will sort an array of strings also called "Onegin"
*/
int main (int argc, char* argv[]) {

    if (argc > 1 and strcmp (argv[1], "--test") == 0) {
        unit_test ();
        return 0;
    }

    FILE* input = fopen ("onegin", "r");

    char* lines[6000] = {0};
    char* temp        = NULL;
    int line_cnt      = 0;

    for (int i = 0; i < 6000; i++) {
        
        if (fgets (temp, 100, input) == NULL) break;
    }

    

}