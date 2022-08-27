#include "protos.h"

int main (int argc, char* argv[]){

	printf("Input string to apply stuff to: ");
	
	char* s = "";
	if (my_getline(s) == MEM_LIM) return -1;

	printf("%s", s);
}	