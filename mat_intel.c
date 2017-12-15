#include <stdio.h>
#include <mkl.h>
#include "matrix.h"
int main(){
	load();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, B, n, 0, C, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%lf ", C[n*i+j]);
		puts("");
	}
	return 0;
}
