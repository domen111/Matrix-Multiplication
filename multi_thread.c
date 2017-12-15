#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "matrix.h"
pthread_t tid[MAX];
double BT[MAX*MAX];
void *process(void *args) {
	int i = *(int*)args;
	for(int j = 0; j < n; j++) {
		C[i*n+j] = 0;
		for(int k=0; k<n; k++)
			C[i*n+j] += A[i*n+k] * BT[j*n+k];
	}
}
int main(){
	load();

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			BT[j*n+i] = B[i*n+j];
		}
	}
	for(int i = 0; i < n; i++) {
		int *tmp = malloc(sizeof(int));
		*tmp = i;
		pthread_create(&tid[i], NULL, process, (void*)tmp);
	}
	for(int i = 0; i < n; i++) {
		pthread_join(tid[i], NULL);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%lf ", C[i*n+j]);
		puts("");
	}
	return 0;
}
