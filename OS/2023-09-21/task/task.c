#include <stdio.h>
#include <stdlib.h>
#include "pushkin.h"

int main(int argc, char** argv){
	int size = 9;
	char c = 0;
	int i = 0;
	int j = 0;
	char* res = (char*)malloc(sizeof(char));
	int res_S = 0;
	for (int i = 0; i < size + 1; ++i){
		if (i == size){
			while ((c = poem[j]) != 0x0a){
				res[res_S] = c;
				++j;
				++res_S;
				res = realloc(res, (res_S + 1) * sizeof(char));
			}
			printf("\n");
		++j;	
		}
		else{
			while ((c = poem[j]) != 0x0a){
				++j;
			}
			++j;
		}
	}
	printf("%s\n", res);

}
