#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
    
    int n; cin >> n;
    vector<int> ds_depth;
    ds_depth.assign(3000010, 0);
    set<int> ds_num;
    
	// OMG, I spend 5 hours to figure this out!!!!!!!!!! 
	long count = 0;
    
	// Input the first node to the tree, as well as updating the ds_depth and ds_num;
	int first_num; cin >> first_num;
    ds_depth[first_num] = 0;
    ds_num.insert(first_num);
    cout << "0" << endl;
    
    for (int i = 0; i < n-1; i++){
		int depth_1 = 0;
    	int depth_2 = 0;
    	
    	int num; cin >> num;
    	ds_num.insert(num);
    	
		// 2 pointers to check if num is the left leave or right leave
		auto iter_1 = ds_num.find(num);
    	auto iter_2 = ds_num.find(num);
    	
    	
    	// check if num is not the smallest element in the tree and is a right leave
    	if (iter_1 != ds_num.begin()){
    		--iter_1;
    		depth_1 = ds_depth[*(iter_1)] + 1; // if num is a right leave, depth = the depth of previous smaller num + 1
		}
		
		// check if num is not a max element and is a left leave
		++iter_2;
		if (iter_2 != ds_num.end()){
			depth_2 = ds_depth[*(iter_2)] + 1; // if num is a left leave, depth = the depth of next larger num + 1;
		}
		
		depth_1 = max(depth_1, depth_2); // the higher depth is the real one
		ds_depth[num] = depth_1; // Update the real depth to the vector 
		
		count += depth_1;
		cout << count << endl;
	}
    
    
    return 0;
}
