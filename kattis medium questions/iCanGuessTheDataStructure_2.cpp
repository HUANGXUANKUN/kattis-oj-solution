#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("iCanGuessTheDataStructure.txt", "r", stdin);
	int n;
	while (cin >> n && !cin.eof()){
		queue<int> queue_test;
		stack<int> stack_test;
		priority_queue<int> pq_test;
		bool isQueue = true, isStack = true, isPq = true;
		
		for (int i = 0; i < n; i++){
			int command; cin >> command;
			int temp; cin >> temp;
			if (command == 1){
				queue_test.push(temp);
				stack_test.push(temp);
				pq_test.push(temp);
			}
			
			else{
				if (stack_test.size()>0 && isStack){
					if (stack_test.top() != temp) isStack = false;
					else stack_test.pop();
				}
				else isStack = false;
				
				if (queue_test.size()>0 && isQueue){
					if (queue_test.front() != temp) isQueue = false;
					else queue_test.pop();
				}
				else isQueue = false;
				
				if (pq_test.size()>0 && isPq){
					if (pq_test.top() != temp) isPq = false;
					else pq_test.pop();
				} 
				else isPq = false;

				// break the case if impossible after loading all the remaining command
				if (!isQueue && !isStack && !isPq){
					for (int j = 0; j < n - i - 1; j++){
						int dump1; cin >> dump1;
						int dump2; cin >> dump2;
					}
					break;
				}
			}
		}
		
		if (!isStack && !isQueue && !isPq) cout << "impossible" << endl;
		else if (isStack && !isQueue && !isPq) cout << "stack" << endl; 
		else if (!isStack && isQueue && !isPq) cout << "queue" << endl; 
		else if (!isStack && !isQueue && isPq) cout << "priority queue" << endl; 
		else cout << "not sure" << endl;	
		cout << endl;		
	}
	
	return 0;
}

