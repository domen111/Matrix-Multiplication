#include <iostream>
#include <random>
using namespace std;
int main()
{
	mt19937 mt(53168755);

	const int n = 8000;
	cout<<n<<'\n';
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<mt()%100<<" \n"[j==n-1];
		}
		cout<<'\n';
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<mt()%100<<" \n"[j==n-1];
		}
		cout<<'\n';
	}
}
