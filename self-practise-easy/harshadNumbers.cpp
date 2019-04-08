#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	bool isHarshadNum = false;
	int sum;
	int temp_n;
	int bin;
	int num;
	while (true) {
		temp_n = n;
		sum = 0;
		
		while (temp_n > 0) {
			bin = temp_n % 10;
			sum += bin;
			temp_n /= 10;
		}
		
		if (n%sum == 0) {
			printf("%d", n);
			break;
		}
		else {
			n++;
		}
	}
}
