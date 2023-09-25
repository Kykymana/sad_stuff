#include <stdio.h>

#ifndef MY_NAME
#define MY_NAME "World"
#endif

#ifdef DEBUG_MODE
#define DEBUG(msg) fprintf(stderr, "[%s:%d] %s: %s\n", \
	__FILE__, __LINE__,__func__, (msg))
#endif
int function(char* name){
	DEBUG("start");
	printf("Hello, %s\n", name);
	DEBUG("End");
}
int main(int argc, char** argv){
	DEBUG("start");
	function(MY_NAME);
	}
