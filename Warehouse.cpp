#include <bits/stdc++.h>
using namespace std;


struct comp{
	//  I have a question to ask, what is the different bewteen line 6 and 7? Is there any risk of writing it as line 7?
    //	bool operator() (const pair<string, int>& lhs, const pair<string, int>& rhs) const {
	bool operator() (pair<string, int> lhs, pair<string, int> rhs){
		if (lhs.second == rhs.second){
			return (lhs.first < rhs.first);
		}
		return (lhs.second > rhs.second);
	}
} myComp;

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input_warehouse.txt", "r", stdin);
	int T; cin >>T;
	while(T--){
		int n; cin >> n;
		map<string, int> ds;
		vector<pair<string, int>> sorted_ds;
		while(n--){
			string name; cin >> name;
			int num; cin >> num;
			ds[name] += num;
		} 		
		
		// Import data from hashtable to a vector for sorting
		for (auto&v:ds){
			sorted_ds.push_back(make_pair(v.first,v.second));
		}
				
	    // sorting
		sort(sorted_ds.begin(), sorted_ds.end(), myComp);
		
		cout << sorted_ds.size() << endl;
		for (auto&v: sorted_ds){
			cout << v.first << " "<< v.second << endl; 
		}
	}
	return 0;
}

