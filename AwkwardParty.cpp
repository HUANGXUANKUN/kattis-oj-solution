#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input_party.txt", "r", stdin);
	int n; cin >> n;
	unordered_map<int, int>ds;
	int minDist = n;
	bool noSame = true;
	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		if (ds.count(temp) > 0){
			minDist = min(minDist, i - ds[temp]);
			noSame = false;
		}
		ds[temp] = i;		
	}
	cout << minDist << endl;
}

