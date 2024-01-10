#define __LIBRARY__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

_syscall1(int, iam, const char*, name);

int main(int argc, char* argv[]){
	int len = 0;
	len = iam(argv[1]);
	if(len<0){
		printf("err!");
	}
	return len;
}
