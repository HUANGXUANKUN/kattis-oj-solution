#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int Y;
	int n;
	scanf("%d %d", &N, &Y);
	bool X[N];
	memset(X, false, sizeof X);
	int danger_count = Y;
	for (int i = 0; i < Y; i++){
		scanf("%d", &n);
		if (!X[n]) {
			X[n] = true;
		}
		else{
			danger_count--;
		}
	}
	for (int i = 0; i < N; i++){
		if (!X[i]){
			printf("%d\n", i);
		}
	}
	printf("Mario got %d of the dangerous obstacles.\n", danger_count);
	return 0;
}
