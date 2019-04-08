#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int Q;
	scanf("%d %d", &N, &Q);
	
	int loc[N];
	memset(loc, 0, sizeof loc);
	
	int pos;
	int type, C, X;
	int dist;
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &pos);
		loc[i] = pos;
	}
	
	for (int i = 1; i <= Q; i++) {
		scanf("%d %d %d", &type, &C, &X);
		if (type == 1) {
			loc[C] = X;
		}
		else {
			dist = abs(loc[C] - loc[X]);
//			printf("loc %d %d\n", loc[C], loc[X]);
			printf("%d\n", dist);
		}
	}
	return 0;
}
