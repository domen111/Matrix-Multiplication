#include <stdio.h>
#define MAX 8000
double A[MAX*MAX] = {};
double B[MAX*MAX] = {};
double C[MAX*MAX] = {};
int n;
void load() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%lf", &A[i*n+j]);
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%lf", &B[i*n+j]);
		}
	}
}
