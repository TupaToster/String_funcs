#include "protos.h"

/*!
    \brief Tests correctness of work of some functions
*/
void unit_test () {

    FILE* test_io = fopen("utest", "a+");
    char* a = (char*) malloc (10);
    char* b = (char*) malloc (12);
    strcpy (a, "abc");
    strcpy (b, "def");
    
    ///< Test of fgets
    fputs ("abs", test_io);
    fseek (test_io, 0, SEEK_SET);
    ASRT (my_fgets (&a, test_io) == OK);
    ASRT (strcmp ("abs", a) == 0);
    ///< EOTest of fgets

    ///< Test of fputs
    ASRT (my_fputs ("abc", test_io) == OK);
    fseek (test_io, 3, SEEK_SET);
    a = fgets (a, 4, test_io);
    ASRT (strcmp ("abc", a) == 0);
    ///< EOTest of fputs

    fclose (test_io);
    test_io = fopen ("utest", "w");
    fclose (test_io);

    ///< Test of strcat
    strcpy (a, "abc");
    strcpy (b, "def");
    ASRT (my_strcat (b, &a) == OK);
    ASRT (strcmp (a, "abcdef") == 0);
    ///< EOTest of strcat

    ///< Test of strncat
    strcpy (a, "abc");
    strcpy (b, "def");
    ASRT (my_strncat (b, &a, 2) == OK);
    ASRT (strcmp (a, "abcde") == 0);
    ///< EOTest of strncat

    ///< Test of strchr
    strcpy (a, "abcdebdef");
    b = my_strchr (a, 'b');
    ASRT (b != NULL);
    ASRT (strcmp (b, "bcdebdef") == 0);
    ///< EOTest of strchr

    ///< Test of strdup
    strcpy (a, "abc");
    ASRT (a != NULL);
    b = my_strdup (a);
    ASRT (b != NULL);
    ASRT (strcmp (b, "abc") == 0);
    ///< EOTest of strdup

    ///< Test of strlen
    strcpy (a, "abc");
    ASRT (my_strlen (a) == 3);
    ///< EOTest52

    ///< Test of strcpy
    strcpy (a, "abc");
    ASRT (my_strcpy (a, b) == OK);
    ASRT (strcmp (a, b) == 0);
    ///< EOTest of strcpy

    ///< Test of strncpy
    strcpy (a, "abc");
    strcpy (b, "abc");
    ASRT (my_strncpy (a, b, 2) == OVERFL);
    ASRT (strcmp (b, "ab") == 0);
    ///< EOTest of strncpy

    ///< Test of smart_strcpy
    strcpy (a, "");
    ASRT (my_smart_strcpy ("abc", &a) == OK);
    ASRT (strcmp (a, "abc") == 0);
    ///< EOTest of smart_strcpy
    
}