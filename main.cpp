#include "protos.h"

void my_merg (char** l, char** r) {

    //printf ("%s\n", *l);
    if (r == l+1) return;
    char** mid = l + (r - l) / 2;
    char** l_ptr = l;
    char** r_ptr = mid;
    my_merg (l, mid);
    my_merg (mid, r);
    char** temp = (char**) calloc (r - l, sizeof(char*));

    for (int i = 0;i < r - l; i++) {

        if (l_ptr != mid) {

            if (r_ptr != r) {

                if (strcmp (*l_ptr, *r_ptr) < 0) {

                    temp[i] = *l_ptr;
                    l_ptr++;
                }
                else {

                    temp[i] = *r_ptr;
                    r_ptr++;
                }
            }
            else {

                temp[i] = *l_ptr;
                l_ptr++;
            }
        }
        else {
            
            temp[i] = *r_ptr;
            r_ptr++;
        }
    }

    for (int i = 0; i < r - l; i++) {

        *l = temp[i];
        l++;
    }
    return;
}
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

    FILE* onegin = fopen ("qtest", "r"), 
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

    my_merg (lines, lines + line_amount);

    for (unsigned int i = 0; i < line_amount; i++) {

        fputs (lines[i], stdout);
    }

}