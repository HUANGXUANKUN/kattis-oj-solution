	#include <bits/stdc++.h>
	using namespace std;
	
	int main() {
		int N;
		int b;
		float t;
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d %f", &b, &t);
			printf("%4f %4f %4f\n", 60*(b-1)/t, 60*(b)/t, 60*(b+1)/t);
		}
	}
