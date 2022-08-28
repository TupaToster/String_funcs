#include "protos.h"

/*!
	\brief Copies one string to another
	\param from - pointer to a pointer to the first elem of string to copy from
	\param to - pointer to a pointer to the first elem of string to copy to
	\return OK - if all ok
	\return MEM_LIM - if there is no mem left to copy

	ладно я сейчас все пофикшу как только разбирусь с гитомы
*/

action_status my_strcpy (char** from, char** to) {
	
	assert (from  != NULL);
	assert (to    != NULL);
	assert (*from != NULL);
	assert (*to   != NULL);
	                              
	*to = (char*) malloc (sizeof_string (*from));
	
	for (unsigned int iter = 0; (*from)[iter] != '\0'; iter++) (*to)[iter] = (*from)[iter];
	
	(*to)[iter] = '\0';
	return OK;
}

action_status my_strncpy (char** from, char** to, unsigned int n) {
	
	assert (from  != NULL);
	assert (to    != NULL);
	assert (*from != NULL);
	assert (*to   != NULL);

	(*to) = (*char) malloc(sizeof_string(*from) < n : sizeof_string(*from) : n);
				
}                   










