#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

double helper(double arr[], int size, double var){
	double result = 0;
	int i;
	for ( i = 3; i < size + 4; i ++){
		result += arr[i] * pow(var, size + 4 - i);
	}
	return result;

}

double computeRoot(double arr[], int size){
	double mid;
	while (1){
		mid = (arr[1] + arr[2])/2;
		if (helper(arr, size, mid) == 0 || (arr[2] - arr[1])/2 < arr[0]){
			return mid;
		}
		if (helper(arr, size, mid) * helper(arr, size, arr[1]) >= 0){
			arr[1] = mid;
		}else{
			arr[2] = mid;
		}
	}
}

int main(int argc, char **argv){
	if (argc != 2){
		printf("Invalid input\n");
		exit(0);
	}
	if ( access( argv[1], F_OK) == -1){
		printf("File doesn't exist\n");
		exit(0);
	}

	FILE *f = fopen(argv[1], "r");
	int n;
	fscanf(f, "%d", &n);	//the number of items
	double func[n + 4];
	int i;
	for ( i = 0; i < n + 4; i++){
		fscanf(f, "%lf", &func[i]);
	}
	fclose(f);
	FILE *out = fopen("part2_solver.dat", "w+");
	fprintf(out, "%lf", computeRoot(func, n));
	fclose(out);
	return 0;
}

