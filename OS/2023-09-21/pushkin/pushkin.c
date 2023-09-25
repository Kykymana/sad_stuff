#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pushkin.h"

char* pushkin(char *str){
	//int size = str;
	char c = 0;
	int i = 0;
	int j = 0;
	char* res = (char*)malloc(sizeof(char));
	int res_S = 0;
	int skip = 0;
	char* end = NULL;
	char* nextel = NULL;
	if(str == NULL){
		end = strchr(poem, 0x0a);
		res = realloc(res, (end - poem) * sizeof(char));
		strncpy(res, poem, (end - poem + 1) * sizeof(char));
		return res;
	}
	end = strchr(poem + strlen(str), 0x0a);
	res = realloc(res, (end - poem) * sizeof(char));
	strncpy(res, (poem + strlen(str)), (end - poem - strlen(str) + 1) * sizeof(char));
	/*for (int i = 0; i < size + 1; ++i){
		if (i == size){
			nextel = strchr(poem + skip, 0x0a);
			res = realloc(res, (nextel - poem) * sizeof(char));
			strncpy(res, poem, (nextel - poem + 1) * sizeof(char));
		}
		else{
			nextel = strchr(poem + skip, 0x0a);
			skip = nextel - poem + 1;
		}
	}*/
	return res;
}




