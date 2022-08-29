// (C) Poltorashka, Inc.
/*!
	\file
	A file that stores basic functions such as string_size and my_getline
	
*/

#include "protos.h"


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
action_status my_getline (char** str, FILE* input) {                                       
	
	assert ( str != NULL);
	assert (*str != NULL);	      

	unsigned int iter 	  = 0;
	int char_in 		  = fgetc(input);
	unsigned int str_size = string_size(*str);
	
	while (char_in != '\n' and char_in != EOF) {
		
		if (iter == str_size) {
			
			str_size *= 2;                  
			*str = (char*) realloc (*str, str_size);
			if (*str == NULL) {
				return MEM_ERR;
			}		
		}
		(*str)[iter] = (char) char_in;
		iter++;
		char_in = fgetc (input);
	}
	str_size = iter + 1;
	*str = (char*) realloc (*str, str_size);
	if (*str == NULL) {
		return MEM_ERR;
	}
	str[iter] = '\0';
	return OK;
}















