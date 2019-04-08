#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	unordered_set<char> ds_letter({'1','2','3','4','5','6','7','8','9','0'});
	map<double,string>ds_color;
	
	for (int i = 0; i < n; i++){
		string a; cin >> a;
		string b; cin >> b;

		// if (diameter, color)
		if (ds_letter.count(a[0])){
			ds_color[(double)(stoi(a))/2] = b;
//			cout << (double)(stoi(a))/2 << endl;
		}
		// if (color, radius)
		else{
			ds_color[stoi(b)] = a;
		}
		
	}
	for (auto&v:ds_color){
		cout << v.second << endl;
	}

}

