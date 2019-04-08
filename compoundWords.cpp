#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	string a;
	unordered_set<string>ds_1;
	set<string>ds_2;
	while(cin >> a){
		ds_1.insert(a);
	}
	for(auto&v:ds_1){
		for(auto&k:ds_1){
			if(v != k){
				string c = v+k;
				ds_2.insert(c);
			}
		}
	}
    for(auto&v:ds_2){
    	cout << v << endl;
	}

}

