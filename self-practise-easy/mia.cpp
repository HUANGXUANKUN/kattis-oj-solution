#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, a2;
	int b1, b2;
	int aV; 
	int bV;		
	cin >> a1; 
	cin >> a2;		
	cin >> b1; 
	cin >> b2;
	while (a1 != 0 && a2 != 0 && b1 != 0 && b2 != 0) {

		if ((a1 == 2 && a2 == 1) || (a1 == 1 && a2 ==2)) { 
			aV = 1000;
		} 
		else if (a1 == a2) {
			aV = a1 * 100;
		}
		else{
			aV = max(a1,a2) * 10 + min(a1, a2);
		}

		if ((b1 == 2 && b2 == 1) || (b1 == 1 && b2 ==2)){
			bV = 1000;
		} 
		else if (b1 == b2) {
			bV = b1 * 100;
		}
		else {
			bV = max(b1, b2) * 10 + min(b1, b2);
		}

		if (aV > bV) {
			cout << "Player 1 wins." << endl;
		}
		else if (aV < bV) {
			cout << "Player 2 wins." << endl;
		}
		else {
			cout << "Tie." << endl;	
		}
		
		cin >> a1; 
		cin >> a2;		
		cin >> b1; 
		cin >> b2;
	}
	
	return 0;
}

