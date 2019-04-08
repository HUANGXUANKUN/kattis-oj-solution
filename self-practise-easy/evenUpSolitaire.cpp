#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int debug = 0;
//	freopen("input.txt", "r", stdin);
	int N, temp;
	cin >> N;
	deque<int> list;
	for (int i = 0; i < N; i++){
		cin >> temp;
		list.push_back(temp);
	}
	bool noEvenLeft;
	bool noEvenRight;
	for(int i = 0; i < N-1; i++){
		noEvenLeft = false;
		noEvenRight = false;
		while(!noEvenLeft || !noEvenRight){
			noEvenLeft = true;
			noEvenRight = true;		
			while ((list[i] + list[i+1])%2==0 && i+1 < N){
				list.erase(list.begin()+i, list.begin()+i+2);	
				noEvenRight = false;
				N-=2;
			}
			
			while (i-1 >= 0 && (list[i-1]+list[i])%2==0){
				list.erase(list.begin()+i-1, list.begin()+i+1);
				i--;
				noEvenLeft = false;
				N-=2;
			}
			if (debug){
				for (auto &a : list){
					cout << a << " ";
				}
				cout << "\n";
			}
				
		}
	}
	
//	for (auto &a : list){
//		cout << a << " ";
//	}
//	cout << "\n";
	
	cout << list.size() << endl;
	return 0;
}

