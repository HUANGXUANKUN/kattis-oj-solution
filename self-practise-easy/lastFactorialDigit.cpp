#include <bits/stdc++.h>

int main() {
	int case_num;
	scanf("%d", &case_num);
	int N;
	int lastDigit;
	for (int i = 0; i < case_num; i ++) {
		scanf("%d", &N);
		lastDigit = 1;	
		for (int a = 0; a < N; a ++) {
			lastDigit = (lastDigit * (a+1)) % 10;
//			printf("%d\n", lastDigit);
		}			
		printf("%d\n", lastDigit);
	}
	return 0;
}

