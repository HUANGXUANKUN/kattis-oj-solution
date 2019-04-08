#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("BaconEggsandSpam.txt", "r", stdin);
	int n;
	while(cin >> n,n){
		cin.get();
		map <string, set<string>> foodMap;
		for (int i = 0; i < n; i++){
			string line;
			getline(cin, line);
			istringstream ss1(line);
			string name;
			ss1 >> name;
			string food;
			while (ss1 >> food){
				foodMap[food].insert(name);
			}
		}
		for (auto &v : foodMap){
			cout << v.first << " ";
			for (auto &n: v.second){
				cout << n << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

