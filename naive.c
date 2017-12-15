#include <stdio.h>
#define max 8000
double A[max][max] = {};
double B[max][max] = {};
double C[max][max] = {};
	
int main(){
	for(int i = 0; i < max; i++)
		for(int j = 0; j < max; j++)
			A[i][j] = 1.00, B[i][j] = 1.00, C[i][j] = 0.00;
	for(int i = 0; i < max; i++){
		for(int j = 0; j < max; j++){
			for(int k = 0; k < max; k++)
				C[i][k] += A[i][j]*B[j][k];
		}
	}
	for(int i = 0; i < max; i++){
		for(int j = 0; j < max; j++)
			printf("%lf ", C[i][j]);
		puts("");
	}
	return 0;
}
