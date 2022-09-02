#include "protos.h"


/*!
    \brief Will contain some ways to interact with functions
    \param argc - count of com line args
    \param argv - array of com line args
    \return 0 - if OK

Now will hold a program that will sort an array of strings also called "Onegin"

first it  reads strings from file with name onegin
second it sorts them
and prints them
*/
int main (int argc, char* argv[]) {

    if (argc > 1 and strcmp (argv[1], "--test") == 0) {
        unit_test ();
        return 0;
    }

    FILE* onegin = fopen ("onegin", "r"), 
        * out    = fopen ("out", "w");

    char** lines = NULL;
    char* temp = (char*) calloc (201, 1);
    unsigned int line_amount = 0;

    while (fgets (temp, 200, onegin) != NULL) line_amount++;

    lines = (char**) calloc (line_amount, sizeof (char*));

    fseek (onegin, SEEK_SET, 0);

    for (unsigned int i = 0; i < line_amount; i++) {

        assert (fgets (temp, 200, onegin) != NULL);
        lines[i] = (char*) malloc (strlen(temp) + 1);
        strcpy (lines[i], temp);
        while (lines[i][0] == '\t' or lines[i][0] == ' ') lines[i]++;
    }

    for (unsigned int i = 0; i < line_amount; i++) {

        fputs (lines[i], out);
    }

}