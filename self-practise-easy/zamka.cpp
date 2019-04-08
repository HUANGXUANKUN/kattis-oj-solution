#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int digits);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int L, D, X;
	cin >> L;
	cin >> D;
	cin >> X;
	bool debug = true;	
	int minV = 10001;
	int maxV = 0;
	int sum;
	int i = L;

	for (i; i <= D; i++) {
		sum = sum_of_digits(i); 
		if (sum == X) {
			minV = min(minV, i);
      		maxV = max(maxV, i);
		}
	}
	printf("%d\n%d\n", minV, maxV);
	return 0;
}

int sum_of_digits(int digits){
	int sum = 0;
//	printf("initial sum = %d\n", sum);
	while (digits != 0){
		sum += digits % 10;
		digits/= 10;
	}
	return sum;
}
