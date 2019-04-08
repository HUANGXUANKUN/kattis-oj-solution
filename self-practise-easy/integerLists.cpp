#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int N; cin>> N;
	for (int i = 0; i < N; i++){
		string command; cin >> command;
		int n; cin >> n; 
		string list; cin >> list;
		
		list = list.substr(1,list.size()-2);
		string token;
		deque<int> numList;
		size_t pos = 0;
		bool isError = false;
		
		while((pos = list.find(",")) != string::npos){
			token = list.substr(0, pos);
			if (!token.empty()) numList.push_back(stoi(token));
			list.erase(0,pos+1);
		}
		
		if (!list.empty()) numList.push_back(stoi(list));
		
//		for (int a = 0; a < n; a++){
//			cout <<numList[a] << " ";
//		}
//		cout << endl;
		
		for (int a = 0; a < command.length(); a++){
			if (command[a] == 'D'){
				if (numList.size() > 0) numList.pop_front();
				else{
					isError = true;
					break;
				}
			}
			else if (command[a] == 'R'){
				if (a+1 < command.length() && command[a+1] == 'R'){
				}
				else{
					int end = numList.size()-1;
					for (int j = 0; j < end; j++){
						int temp = numList[j];
						numList[j] = numList[end];
						numList[end] = temp;
						end--;
					}
				}
			}
//			cout << "[";
//			for (int b = 0; b < numList.size() -1; b++){
//				cout << numList[b] << ", ";
//			}
//			cout << numList.back() <<"]" <<endl;

		}
		
		if (isError) cout << "error" << endl;
		else{
			cout << "[";
			for (int a = 0; a < numList.size(); a++){
				if (a != numList.size() -1) cout << numList[a] << ",";
				else cout << numList[a];
			}
			cout <<"]" <<endl;
		}
	}
	
	return 0;	
}

