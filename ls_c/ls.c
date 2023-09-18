#define _POSIXSOURCE 1
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>

static int
   cmpstringp(const void *p1, const void *p2)
   {
       return strcmp(* (char * const *) p1, * (char * const *) p2);
   }


int main(int argc, char** argv){
	struct stat buff;
	FILE* fp = fopen(argv[1], "rw");
	DIR* dir = opendir(argv[1]);
	struct dirent* dre;
	if (argc < 2){
		printf("ERROR\n");
	}
	else{	
		if(dir == NULL){
			printf("ERROR\n");
		}
		else{	
			char PathName[PATH_MAX];
			char PN;
			PN = getwd(PathName);
			printf("Directory %s/%s:\n", PathName, argv[1]);
			char** files = (char**)malloc(sizeof(char*));
			int* size = (int*)malloc(sizeof(int));
			long int sum = 0;
			int count = 0;
			while(NULL != (dre = readdir(dir))){
				files[count] = dre->d_name;
				stat(dre->d_name, &buff);
				size[count] = buff.st_size;
				sum += buff.st_size;
				count += 1;
				files = realloc(files, (count + 1) * sizeof(char*));
				size = realloc(size, (count + 1) * sizeof(int));
			}
			char** backup = (char**)malloc((count + 1) * sizeof(char*));
			for (int i = 0; i < count; ++i){
				backup[i] = files[i];
			} 
			qsort(files, count, sizeof(char*), cmpstringp);
			for (int i = 0; i < count; ++i){
				for (int j = 0; j < count; ++j){
					if (strcmp(backup[j], files[i]) == 0){
						printf("%d %s\n", size[j], files[i]);
					}
				}	
			}
			printf("Total of %ld bytes in %d files\n", sum, count);
		}
	}
	
}
