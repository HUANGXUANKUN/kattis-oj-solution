#include <bits/stdc++.h>
using namespace std;

bool execute(int X[], int ram[], int a, int d, int n, int& exeCount, int& j);

int main() {
	int a, d, n;
	int reg[10];
	int ram[1000];
	memset(reg, 0, sizeof reg);
	memset(ram, 0, sizeof ram);
	int exeCount = 0;
	int instruction;
	int ram_len = 0;
	int command = 0;
	bool isHalt = false;
	while (cin >> command) {
		ram[ram_len] = command;
		ram_len++;
	}

//  	printf("ram_len is %d\n", ram_len);
	for (int j = 0; !isHalt; j++) {
		instruction = ram[j];
		a = instruction / 100 % 10;
		d = instruction / 10 % 10;
		n = instruction % 10;
		isHalt = execute(reg, ram, a, d, n, exeCount, j);
		if (exeCount >= 10000)
			break;
		if (isHalt)
			break;
	}
	printf("%d\n", exeCount);
	return 0;
}

bool execute(int X[], int ram[], int a, int d, int n, int& exeCount, int& j) {
	bool isHalt = false;
	if (exeCount >= 10000)
		return isHalt = true;
	exeCount++;

//	printf("%d%d%d\n", a, d, n);
//	for (int i = 0; i < 10; i ++)
//  		printf("%d X[%d] is %d\n", exeCount, i, X[i]);
//
//  	printf("\n");


	if (a == 1) {
		isHalt = true;
		return isHalt;
	}

	else if (a == 2) {
		X[d] = n;
		X[d] %= 1000;
	}

	else if (a == 3) {
		X[d] += n;
		X[d] %= 1000;
	}

	else if (a == 4) {
		X[d] *= n;
		X[d] %= 1000;
	}

	else if (a == 5) {
		X[d] = X[n];
	}

	else if (a == 6) {
		X[d] += X[n];
		X[d] %= 1000;
	}

	else if (a == 7) {
		X[d] *= X[n];
		X[d] %= 1000;
	}

	else if (a == 8) {
		int ram_add = X[n];
		X[d] = ram[ram_add];
	}

	else if (a == 9) {
		int ram_add = X[n];
		ram[ram_add] = X[d];
	}

	else if (a == 0) {
		int reg_s = X[n];

		if (reg_s!= 0) {
			int ram_add = X[d];
			j = ram_add -1;
		}

	}

	return isHalt;

}
