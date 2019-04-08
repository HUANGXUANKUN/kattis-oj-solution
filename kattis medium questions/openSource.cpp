#include <bits/stdc++.h>
using namespace std;
struct comp{
	bool operator()(const pair<string,int>&a,const pair<string,int>&b)const{
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
}cmp;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	string temp;
	unordered_map<string, unordered_set<string>>ds;
	unordered_map<string,unordered_set<string>>ds_2;
	vector<pair<string,int>>ds_3;
	string proj;
	while(getline(cin,temp)){
		char c = temp[0];
		if (c == '1'){
//			 for all student registered proj
			for(auto&v:ds_2){
				// if the student has reg for more than 1 proj
				if(v.second.size() > 1){
//					cout << v.first << "to be removed" << endl;
					// scan thru all proj registration to remove that student from all proj
					for(auto&c:ds){
						// if the proj has this student name(v.first), erase it
						if(c.second.count(v.first)>0){
							c.second.erase(v.first);
						}
					}
				}
			}
			for(auto&v:ds){
				pair<string,int> temp = make_pair(v.first, v.second.size());
				ds_3.push_back(temp); 
			}
			sort(ds_3.begin(), ds_3.end(),cmp);
			
			for(auto&v:ds_3){
				cout << v.first << " " << v.second<<endl;
			}
			ds.clear();
			ds_2.clear();
			ds_3.clear();
		}
		
		else if (c == '0'){
			break;
		}
		// if temp is a name
		else{
			// if capital letter, proj name update
			char low_c = tolower(c);
			if (low_c != c){
				// update the project
				proj = temp;
				unordered_set<string>temp;
				ds[proj] = temp;
//				cout << "make proj to "<< proj <<endl;
			}
			//lowercase, student name
			else{
				ds[proj].insert(temp);
				ds_2[temp].insert(proj);
//				cout << "insert " << temp << "to " << proj<<endl;
			}
		}
	}
	return 0;
}

