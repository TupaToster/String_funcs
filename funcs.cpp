/*!
	\file
	A file to store basic string functions (for now at least)
*/

#include <protos.h>


/*!
	\brief Calculates string's size
	\param str - pointer to string's first element
	\return Full string size including '\0'
*/
unsigned int string_size (const char* str) {

	assert (str != NULL);
	
	unsigned int size = 1;
	for (size = 1; str[size] != '\0'; size++);

	return size;
}

/*!
	\brief Reads line from stdin
	\param str - pointer to string's first element
	\return OK - string read, all ok
	\return MEM_LIM - program ran out of free memory

Also dynamically changes string's size to match the input
*/
input_status my_getline (char** str) {

    assert (str != NULL);
	
	unsigned int       iter = 0;
	unsigned int sizeof_str = string_size (*str);
	int             in_char = fgetc (stdin);

	while (in_char != '\n' and in_char != EOF) {
	
		if (sizof_str == iter) {
			
			sizeof_str *= 2;
			*str = realloc (*str, sizeof_str);
			if (*str == NULL){
				printf("Your pc happened to run out of free memory \n");
				return MEM_LIM;
			}							
		}
		
	    *str[iter] = in_char;
		iter++;
	}		
	
	*str[iter] = '\0';
	return OK;
}