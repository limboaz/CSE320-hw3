#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	FILE* fp = fopen("false", "r");
	int d;
	printf("%d\n", fscanf(fp, "%d", &d));
	return 0;
}
