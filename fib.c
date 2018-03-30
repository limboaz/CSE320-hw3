#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint64_t fib(int n){
	if ( n == 0)
		return 0;
	else if ( n == 1)
		return 1;
	
	uint64_t arr[n+1];
	arr[0] = 0;
	arr[1] = 1;
	int i;
	for( i = 2; i <= n; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main(int argc, char **argv){
	if ( argc != 2 ){
		printf("Wrong input\n");
	}
	int n = atoi(argv[1]);
	if ( n < 0){
		printf("Illegal input\n");
	}
	FILE *f = fopen("part2_fib.dat", "w+");
	fprintf(f, "%lu", fib(n));
	fclose(f);
	return 0;
}
