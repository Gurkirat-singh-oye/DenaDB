#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

#define FALSE 0
#define TRUE 1

typedef void (*func)(void);
typedef char* cmds;

void exit_cmd() {
	printf("goodbye!\n");
	exit(0);
}

void help_cmd() {
	printf("pending\n");
}


cmds cmdarray[MAP_SIZE] = { ".exit", ".help"};
func funcarray[MAP_SIZE] = { &exit_cmd, &help_cmd};
map hashmap[MAP_SIZE];

void initdena(){

	// initialization of map for commands
	int i = 0;
	while(i < 2){
		mapinskv(cmdarray[i], funcarray[i], hashmap);
		i++;
	}
	printf("DenaDB version 0.1\n");
}

void sqlstatementhandler(char* stmt){
	// tokenize
	// parse
	// codegen
	// bytecodeegine
	// b-tree
	// page cache and os interface
	printf("situation handled\n");
}

void processinput(char *cmd){
	cmd[strcspn(cmd, "\n")] = 0;

	// commands
	if (cmd[0] != '.'){
		sqlstatementhandler(cmd);

	// sql commands
	} else {
		void (*cmdfunc)(void);
		cmdfunc = mapgetkv(cmd, hashmap);
		cmdfunc();
	}
}
