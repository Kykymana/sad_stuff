#include <stdio.h>
#include <stdlib.h>
#ifndef NO_SHARED
char* pushkin(char* str);
#endif


#ifdef NO_SHARED
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <string.h>


char buffer[PATH_MAX];
void *handle = NULL;
char *(*pushkin)(char *) = NULL;

int find_lib(char *path){
	DIR* cur_dir = opendir(path);
	struct dirent* cur_dirent;
	while((cur_dirent = readdir(cur_dir)) != NULL){
		char *file = (char *)calloc(sizeof(char), strlen(path) + strlen(cur_dirent->d_name) + 1);
		sprintf(file, "%s/%s", path, cur_dirent->d_name);
		struct stat cur_file_stat;
		lstat(file, &cur_file_stat);
		if(S_ISDIR(cur_file_stat.st_mode)){
			if(strcmp(cur_dirent->d_name, ".") && strcmp(cur_dirent->d_name, "..")){
				find_lib(file);
			}
		} else if(S_ISREG(cur_file_stat.st_mode)){
			char *ext;
			if( (ext = strrchr(cur_dirent->d_name, '.')) != NULL){
				if(!strcmp(ext, ".so")){
					if( (handle = dlopen(file, RTLD_LAZY)) != NULL ){
						pushkin = dlsym(handle, "pushkin");
					}				
				}
			}
			ext = NULL;
		}
	}
	return 0;
}


#endif


int main(int argc, char** argv){
#ifndef NO_SHARED
	char* str = pushkin("У лукоморья дуб зеленый,\nЗлатая цепь на дубе том:\nИ днем и ночью кот ученый\n");
	printf("%s", str);
#endif

#ifdef NO_SHARED
	int i = find_lib(".");
	if (handle == NULL || *(pushkin) == NULL){
		printf("ERR\n");
		return -2;
	}
	char* str = pushkin("У лукоморья дуб зеленый,\nЗлатая цепь на дубе том:\nИ днем и ночью кот ученый\n");
	printf("%s", str);
#endif
}
