#include <bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator()(string lhs,  string rhs){
		for (auto&c:lhs){
			c = tolower(c);
		}
		for (auto&c:rhs){
			c = tolower(c);
		}
		return lhs < rhs;
	}
}myComp;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int r, c;
	
	while (cin >> r && cin >> c && (r&&c)){
		vector<string>ds;
		ds.assign(c, "");
		for (int i = 0; i < r;i++){
			for (int j = 0; j < c; j++){
				char temp; cin >> temp;
				ds[j].push_back(temp);
			}
		}
		
		stable_sort(ds.begin(), ds.end(), myComp);
		
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cout << ds[j][i];
			}
			cout << endl;
		}
		cout << endl;
			
	}
	return 0;

}

