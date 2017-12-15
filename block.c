#include "stdio.h"
#include "matrix.h"
#define block_size 256
int main(int argc, char*  argv[])
{
	load();

	// Initalize our matix looping variables once
	int k, j, i, jj, kk;

	// Do block matrix multiplication
	for (k = 0; k < n; k += block_size)
		for (j = 0; j < n; j += block_size)
			for (i = 0; i < n; ++i)
				for (jj = j; jj < (j + block_size < n? j+block_size : n); ++jj)
					for (kk = k; kk < (k + block_size <  n? k+block_size : n); ++kk)
						C[i*n+jj] += A[i*n+kk] * B[kk*n+jj];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%lf ", C[i*n+j]);
		puts("");
	}
	return 0;
}
