#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int X[n];
	int minDay;
	int minV = 1e9 +1;
	int junkV;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &junkV);
		if (junkV < minV) {
			minV = junkV;
			minDay = i;
		}
	}
	printf("%d", minDay);
}
