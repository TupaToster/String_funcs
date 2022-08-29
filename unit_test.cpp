// (C) Poltorashka, Inc.
#include "protos.h"

void unit_test () {
	
    // Test of my_getline() function
    FILE* test_input = NULL;
    test_input = fopen ("test_input.txt", "r");
    assert (test_input != NULL);
    
    char* test_str = (char*) malloc (4);

    my_getline (&test_str, test_input); 
    
    ASRT (strcmp (test_str, "abc") == 0);
    ASRT (strlen (test_str) == 3);
    //EOTest
    
    

}