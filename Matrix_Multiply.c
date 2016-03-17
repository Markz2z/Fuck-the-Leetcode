#include "stdio.h"

#define M 2
#define N 4

//matrix1 int[M][N]
//matrix2 int[N][M]
//[1 2 3 4]        [6 7]
//[4 5 6 8] 	   [8 9]
//			       [1 2]
//			       [3 4]
//M = 2, N = 4
void Multiply(int** matrix1, int** matrix2, int** result) {
	int i, j, k;
	for(i=0;i<M;i++) {
		for(j=0;j<M;j++) {
			int res = 0;
			for(k=0;k<N;k++) {
				//res += matrix1[i][k] * matrix2[k][j];
				res += matrix1[0][0] * matrix2[0][0];
				//printf("%d\n", *(int*)(*(int**)(matrix1)) );
			}
			printf("%d\n", res);
			//result[i][j] = res;
		}
	}
}

int main() {
	// int ** ptr1 = NULL;
	// int ** ptr2 = NULL;
	// int ** ptr3 = NULL;
	// int a[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
	// int b[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 9}};
	// int result[2][2];
	// ptr1 = a;
	// ptr2 = b;
	// ptr3 = result;
	// Multiply(ptr1, ptr2, ptr3);
	// for(int i = 0; i < M; i++) {
	// 	for(int j = 0; j < M; j++)
	// 		printf("%d ", result[i][j]);
	// 	printf("\n");
	// }
	int a[10];
	a[0] = 5;
	a[1] = 1210;
	int * b = a;
	printf("%p\n", a);
	printf("%p\n", &(a[0]));
	printf("%p %p\n", b, b+1);
	printf("%d\n", *(b+1));
	return 1;
}