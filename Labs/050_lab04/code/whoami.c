#define __LIBRARY__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

_syscall2(int, whoami, char*, name, unsigned int, size);

int main(int argc, char* argv[]){
	char name[24] = {0};
	int len = 0;
	len = whoami(name, 24);
	if(len>=0){
		printf("%s", name);
	}
	return len;
}
