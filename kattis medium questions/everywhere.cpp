#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while(T--){
		int n; cin >>n;
		unordered_set<string>ds;
		while(n--){
			string temp; cin >> temp;
			ds.insert(temp);
		}
		cout << ds.size() << endl;
	}

}

