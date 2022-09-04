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

    FILE* onegin = fopen ("onegin", "r");
    assert (onegin != NULL);
    FILE* out    = fopen ("out", "w");
    assert (out    != NULL);    

    unsigned int line_cnt = 0;
    char* temp = (char*) malloc (200);
    assert (temp != NULL);
    
    while (fgets (temp, 199, onegin) != NULL) line_cnt++;

    fseek (onegin, SEEK_SET, 0);

    char** lines = (char**) calloc (line_cnt + 1, sizeof (char*));
    lines[line_cnt] = (char*) malloc (20);
    strcpy (lines[line_cnt], "end of lol man");

    for (unsigned int i = 0; i < line_cnt; i++) {

        temp = fgets (temp, 199, onegin);
        assert (temp != NULL);
        lines[i] = (char*) malloc (strlen (temp) + 1);
        strcpy (lines[i], temp);
    }

    mergesort_str (lines, lines + line_cnt);

    for (unsigned int i = 0; i < line_cnt; i++) {

        fputs (lines[i], out);
    }
     
}