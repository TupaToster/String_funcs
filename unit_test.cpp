// (C) Poltorashka, Inc.
#include "protos.h"

/*!
    \file
Unit test file that tests correctness of work of functions used in project
*/

void unit_test () {
    FILE* test_io = fopen ("test.txt", "a+"); ///< test input/output stream
    assert (test_io != NULL);
    char* test_str_a = (char*) malloc (4); ///< test string a
    assert (test_str_a != NULL);
    char* test_str_b = (char*) malloc (4); ///< test string b
    assert (test_str_b != NULL);

    
    

}