#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAP_SIZE 29


// implementation of map
typedef struct {
	char* key;
	void (*funcptr)(void);
} map;

long long int hashof (char* cmd) {
	long long int i = 0;
	long long int hash = 1;
	while(cmd[i]) {
		// printf("%lli\t%c", hash, cmd[i]);
		long long int mul = (long long int)cmd[i];
		hash = (hash*mul)-(hash*i*i)+i;
		i++;
	}
	return hash;
}

//  collisions to be handled
void mapinskv(char* k, void* fp, map* dic) {
	map mapen;
	mapen.key = k; mapen.funcptr = fp;
	dic[abs((int)hashof(k)%MAP_SIZE)] = mapen;
}

void* mapgetkv(char* k, map* dic) {
	map geten = dic[abs((int)hashof(k)%MAP_SIZE)];
	return geten.funcptr;
}
