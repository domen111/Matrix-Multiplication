#include <stdio.h>
#include "matrix.h"
int main(){
	load();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++)
				C[i*n+k] += A[i*n+j]*B[j*n+k];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%lf ", C[i*n+j]);
		puts("");
	}
	return 0;
}
