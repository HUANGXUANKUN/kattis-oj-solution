#include <bits/stdc++.h>
using namespace std;

int main() {
	string name;
	cin >> name;
	string name2;
	name2 += name.at(0);
	int len = name.length();
	for (int i = 0; i < len; i++) {
		if ((name.at(i)) == '-' && (i < len-1)) {
			name2 += name.at(i+1);
		}
	}
	cout << name2 << endl;
	return 0;
}
