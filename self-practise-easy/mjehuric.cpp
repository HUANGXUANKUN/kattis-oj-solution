#include <bits/stdc++.h>
using namespace std;

int main() {
	int X[5];
	for (int i = 0; i < 5; i++){
		cin >> X[i]; 
	}
	
	int N = 5;
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < N-1; i++) {
			if (X[i] > X[i+1]){
				swap(X[i], X[i+1]);
				swapped = true;
				for (int k = 0; k < 5; k++){
					printf("%d ", X[k]);
				}
				printf("\n");
			}
		}
		N = N-1;
	}
	
	return 0;
}
