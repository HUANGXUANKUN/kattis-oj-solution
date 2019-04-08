#include <bits/stdc++.h>

int main() {
	int N;
	int gap;
	int tag_num;
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		gap = N -1 - i;
		tag_num = N;
		if (i == 0 || i == 1) {
			b = i;
		}
		else {
			b += 2;
		}
			
		for (a = 0; a < gap; a++){
			printf(" ");
		}
		printf("*");
		for (a = 0; a < b; a++){
			printf("#");
		}		
		if (i >= 1)
			printf("*");
		for (a = 0; a < tag_num; a++){
			printf(" ");
		}
		printf("\n");
	}
	for (int c = 0; c < i*2 + 1; c++){
		printf("*");
	}
	return 0;
	
}
