#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header_files/Dena.h"


int main() {
    size_t n;
    char *lineptr;
    
	initdena();
	
    while ( TRUE ) {
        printf("denadb> ");
        getline(&lineptr, &n, stdin);
        processinput(lineptr);
    }

    return 0;
}
