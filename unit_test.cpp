// (C) Poltorashka, Inc.
#include "protos.h"

/*!
    \file
Unit test file that tests correctness of work of functions used in project
*/

void unit_test () {
	
    ///< Test of my_getline() function
    
    FILE* test_io = NULL;///< A file that will serve as an input file
    test_io = fopen ("test_io.txt", "r");
    assert (test_io != NULL);
    
    char* test_str = (char*) malloc (4); ///< test string to 

    my_getline (&test_str, test_io); 
    
    ASRT (strcmp (test_str, "abc") == 0);
    ASRT (strlen (test_str) == 3);
    assert (fclose (test_io) != EOF);
    ///< EOTest of my_getline()

    ///< Test of my_fputs()
    test_io = NULL;
    test_io = fopen ("test_io");
    assert (test_io != NULL);
    


}