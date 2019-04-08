#include <bits/stdc++.h>

int command_i;

using namespace std;

bool cmp(const vector<string>&lhs, const vector<string>&rhs){
	string lhs_a = lhs[command_i];
	string rhs_a = rhs[command_i];
	return lhs_a < rhs_a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	string line;
	getline(cin, line);
	
	
	unordered_map<string, int> ds;
	istringstream iss(line);
	string temp;
	
	// update hashtable for attribute to index
	int index = 0;
	while(iss>>temp){
		ds[temp] = index;
		index++;
	}
	
	vector<vector<string>> ds_2;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		vector<string> vect_temp;
		for (int j = 0; j < ds.size(); j++){
			string a; cin >> a;
			vect_temp.push_back(a);
		}
		ds_2.push_back(vect_temp);
	}
	
	int k; cin >>k;
	for(int i = 0; i < k; i++){
		string command; 
		cin >> command;
		command_i = ds[command];
		stable_sort(ds_2.begin(),ds_2.end(),cmp);
		cout << line << endl;
		for (auto&v:ds_2){
			for(auto&c:v){
				cout << c << " ";
			}
			cout << endl;
		}
		if (i != (k-1)){
			cout << endl;
		}
	}
	
	return 0;
	

}

