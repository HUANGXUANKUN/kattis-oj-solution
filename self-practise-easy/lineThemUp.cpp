#include <bits/stdc++.h>
using namespace std;

void find_order(string nameList[], int N);

int main() {
	int debug = 0;
	
	string nameList[20];
	int N; cin >> N;
	for (int i = 0; i < N; i++){
		cin >> nameList[i];
	}
	
	if (debug) {
		for (int i = 0; i < N; i++){
			cout << nameList[i] << endl;
		}
	}
	
	find_order(nameList, N);
	return 0;
	
}

void find_order(string nameList[], int N) {
	int order = 0;
	for (int i = 1; i < N; i++){
		if (nameList[i-1] < nameList[i]) {
			if (order == -1)
				order = 2;
			else order = 1;
		}
		
		else if (nameList[i-1] > nameList[i]) {
			if (order == 1)
				order = 2;
			else order = -1;
		}
		
		if (order == 2) break;
	}
	switch(order) {
		case 1: cout << "INCREASING" << endl; break;
		case -1: cout << "DECREASING" << endl; break;
		case 2: cout << "NEITHER" << endl; break;
	}
}

