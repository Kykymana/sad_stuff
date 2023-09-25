#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv){
	void* handle;
	void (*pprint)(char*);
	
	handle = dlopen("./libpprint.so", RTLD_LAZY);
	if (NULL == handle){
		printf("%s\n", dlerror());
		return -1;
	}
	pprint = (void (*)(char*)) dlsym(handle, "pprint");
	if (NULL != pprint){
		pprint("Hello world\n");
	}
	else{
		printf("err 2\n");
		return -2;
	}
	dlclose(handle);
	return (NULL == pprint) ? -1 : 0;
}
