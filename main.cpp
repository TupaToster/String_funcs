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

    char* lines[6852] = {NULL},
        * temp        = (char*) calloc (201, 1);

    for (int i = 0; i < 6852; i++) {

        lines[i] = (char*) calloc (201, 1);
        lines[i] = fgets (lines[i], 200, onegin);
        while (lines[i][0] == '\t') lines[i]++;
    }

    for (int i = 0; i < 6852; i++) {

        for (int j = 1; j < 6852; j++) {

            if (strcmp (lines[j], lines[j-1]) < 0) {

                temp = lines[j];
                lines[j] = lines[j-1];
                lines[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < 6852; i++) {

        fputs (lines[i], out);
    }

}