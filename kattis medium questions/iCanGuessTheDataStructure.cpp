#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

// #include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int n;
	bool debug = false;
	
	while (cin >> n && !cin.eof()){
		vector<int> listStack;
		vector<int> listQueue;
		vector<int> listPQ = listStack;
		int x;
		bool isStack = true, isQueue = true, isPQ = true;
		bool isImpossible = false;
		
		for (int i = 0; i < n; i++){
			int a, b;
			cin >> a;
			cin >> b;
			if (a == 1){
				listStack.insert(listStack.begin(), b);
				listQueue.push_back(b);
				listPQ.insert(listPQ.begin(), b);
			}
			else if (a == 2){
				x = b;
			}
		
			if (debug){
				cout << "lists are " << endl;
				for (int j = 0; j < listStack.size(); j++){
					cout << listStack[j] << " ";
				}
				cout << endl;		
				
				for (int j = 0; j < listQueue.size(); j++){	
					cout << listQueue[j] << " ";
				}
				cout << endl;
				
				for (int j = 0; j < listPQ.size(); j++){
					cout << listPQ[j] << " ";
				}
				cout << endl;
				cout << endl;
			}
		
		
			// Check isStack
			if (a == 2 && isStack && !isImpossible){
				if(listStack.size() < 1){
					isStack = false;
					isImpossible = true;
				}
				else{
					int start = listStack.front();
					if(x == start){
						listStack.erase(listStack.begin());
					}
					else{
						isStack = false;
						if ((find(listStack.begin(), listStack.end(), x) == listStack.end())){
							isImpossible = true;
						}
					}
				}
				if(debug) cout << "isStack = " << isStack << endl; 
				if(debug) cout << "isImpossible = " << isImpossible << endl; 
	
			}
		
			// Check isQueue
			if (a == 2 && isQueue && !isImpossible){
				if(listQueue.size() < 1){
					isQueue = false;
					isImpossible = true;
				}
				else{
					int start = listQueue.front();
					if(x == start){
						listQueue.erase(listQueue.begin());
					}
					else{
						isQueue = false;
						if ((find(listQueue.begin(), listQueue.end(), x) == listQueue.end())){
							isImpossible = true;
						}
					}
				}
				if(debug) cout << "isQueue = " << isQueue << endl; 
				if(debug) cout << "isImpossible = " << isImpossible << endl; 
			}
		
			// Check isPQ
			if (a == 2 && isPQ && !isImpossible){
				if(listPQ.size() < 1){
					isPQ = false;
					isImpossible = true;
				}
				else{
					vector<int>::iterator maxNum_it = max_element(listPQ.begin(), listPQ.end());
					int maxNum = *maxNum_it;
					if(debug) printf("x = %d maxNUm = %d\n", x, maxNum);
					if(x == maxNum){
						listPQ.erase(maxNum_it);
					}
					else{
						isPQ = false;
						if ((find(listPQ.begin(), listPQ.end(), x) == listPQ.end())){
							isImpossible = true;
						}
					}
				}
				if(debug) cout << "isPQ = " << isPQ << endl; 
				if(debug) cout << "isImpossible = " << isImpossible << endl; 
	
			}		
		}
		
		if (isImpossible) cout << "impossible" << endl;
		else if (isStack && !isQueue && !isPQ) cout << "stack" << endl; 
		else if (!isStack && isQueue && !isPQ) cout << "queue" << endl; 
		else if (!isStack && !isQueue && isPQ) cout << "priority queue" << endl; 
		else cout << "not sure" << endl;
	}
					
	return 0;
}
