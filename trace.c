#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int helper(int arr1[], int size, int arr2[]){
	int result = 0;
	int i;
	for ( i = 0; i < size; i ++){
		result += arr1[i] * arr2[i];
	}
	return result;
}

int trace(int **mat1, int row, int col, int **mat2, int row2, int col2){
	int c[row][col2];
	int i, j;
	for( i = 0; i < row; i++){
		for( j = 0; j < col2; j++){
			int arr[col];
			int k;
			for ( k = 0; k < col; k++){
				arr[k] = mat2[k][j];
			}
			c[i][j] = helper(mat1[i], col, arr);
		}
	}
	int trace = 0;
	for ( i = 0; i < row; i++){
		trace += c[i][i];
	}
	return trace;
}

int main(int argc, char **argv){
	if (argc != 2){
		printf("Invalid input\n");
	}
	if ( access( argv[1], F_OK) == -1){
		printf("File doesn't exist\n");
		exit(0);
	}

	FILE *f = fopen(argv[1], "r");

	int row;
	int col;
	fscanf(f, "%d %d\n", &row, &col);
	int** mat1 = malloc(row * sizeof(int*));
	int i, j;
	for ( i = 0; i < row; i ++){
		mat1[i] = malloc(col * sizeof(int));
		for( j = 0; j < col; j++){
			fscanf(f, "%d", &mat1[i][j]);
		}
	}
	
	int row2;
	int col2;
	fscanf(f, "%d %d\n", &row2, &col2);
	int** mat2 = malloc(row2 * sizeof(int*));
	for ( i = 0; i < row2; i ++){
		mat2[i] = malloc(col2 * sizeof(int));
		for( j = 0; j < col2; j++){
			fscanf(f, "%d", &mat2[i][j]);
		}
	}
	fclose(f);
	FILE *out = fopen("part2_trace.dat", "w+");
	fprintf(out, "%d", trace(mat1, row, col, mat2, row2, col2));
	fclose(out);
	return 0;

}
