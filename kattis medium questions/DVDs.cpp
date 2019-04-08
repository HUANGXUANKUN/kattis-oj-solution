#include <bits/stdc++.h>
using namespace std;

vector<int>ds;
vector<int>ds_sorted;
unordered_map<int,int>map_sorted;
	
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	while(n--){
		ds.clear();
		ds_sorted.clear();
		int k; cin >>k;
		for (int i = 0; i < k; i++){
			int temp; cin >> temp;
			ds.push_back(temp);
			ds_sorted.push_back(temp);
		}
		
		sort(ds_sorted.begin(),ds_sorted.end());
		for(int i = 0; i < k; i++){
			map_sorted[ds_sorted[i]]= i;
		}
		
		int inorder_len = 0;
		int next_sorted_int= ds_sorted[0];
		for(int i = 0; i < k; i++){
			if(ds[i] == next_sorted_int){
				inorder_len++;
				int next_sorted_index = map_sorted[ds[i]]+1;
				if(next_sorted_index<k){
					next_sorted_int = ds_sorted[next_sorted_index];
				}
				else{
					break;
				}
			}
		}
		cout << k - inorder_len << endl;
	
	}
	
	
}

