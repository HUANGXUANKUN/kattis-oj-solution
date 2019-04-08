#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a;
	cin >> b;
	if (b == 0 && a == 0) {
		cout << "Not a moose\n";
	}
	else if (a == b) {
		cout << "Even " << (a+b) << endl;
	}
	else{
		int maxV;
		maxV = max(a, b);
		cout<< "Odd " << (maxV*2) << endl;
	}
	return 0;
}
