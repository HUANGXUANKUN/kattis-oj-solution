#include <bits/stdc++.h>

using namespace std;

int main() {
	int P;
	scanf("%d", &P);
	int K, b, n;
	int sum;
	int remainder;
	for (int i = 0; i < P; i++) {
		scanf("%d %d %d", &K, &b, &n);
		printf("%d ", K);
		sum = 0;
		while (n > 0) {
			remainder = n % b;
			sum += remainder * remainder;
			n /= b;
		}
		printf("%d\n", sum);
	}
	return 0;
}
