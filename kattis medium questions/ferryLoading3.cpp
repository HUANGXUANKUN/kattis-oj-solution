#include <bits/stdc++.h>
using namespace std;

struct car {
	int inputNum;
	int arrival_t;
	int unloaded_t;
};

// O(nm) solution. n = the max loading car number, m = total number of cars 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("FerryLoading3.txt", "r", stdin);
	bool debug = false;
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		int t;
		cin >> t;
		int m;
		cin >> m;

		// List to record unload time in the same order as the input
		vector<car> carsArrivalList;
		// Two queues to store cars at left and right banks
		queue<car> carsLeft;
		queue<car> carsRight;

		// load m lines of cars
		for (int j = 0; j < m; j++) {
			int time;
			cin >> time;
			string pos;
			cin >> pos;

			car temp;
			temp.inputNum = j;
			temp.arrival_t = time;

			carsArrivalList.push_back(temp);
			if (pos == "left") carsLeft.push(temp);
			else carsRight.push(temp);
		}

		int atLeft = 1;
		bool carsOnboard = false;
		int curr_time = 0;

		while(carsRight.size() > 0 || carsLeft.size() > 0 || carsOnboard) {
			carsOnboard = false;
			
			// Load the cars if there is any waiting
			for (int j = 0; j < n; j++) {
				if (atLeft) {
					if (carsLeft.size() > 0 && carsLeft.front().arrival_t <= curr_time) {
						int index = carsLeft.front().inputNum;

						if(debug) cout << "index = " << index << endl;
						if(debug) cout << "carsLeft.front().arrival_t = " << carsLeft.front().arrival_t << endl;

						carsArrivalList[index].unloaded_t = curr_time + t;
						carsLeft.pop();
						carsOnboard = true;
					}
				} else {
					if (carsRight.size() > 0 && carsRight.front().arrival_t <= curr_time) {
						int index = carsRight.front().inputNum;
//						if(debug) cout << "index = " << index << endl;
						carsArrivalList[index].unloaded_t = curr_time + t;
						carsRight.pop();
						carsOnboard = true;
					}
				}
			}
			
			// Ship the cars to the opposite bank 
			if (carsOnboard) {
				atLeft = 1 - atLeft;
				curr_time += t;
			}
			
			// If no car awaiting at the current bank
			else {
				bool isBankEmpty = false;
				
				// break if no car onboard and all cars have crossed the river
				if ((carsLeft.size() <= 0) && (carsRight.size() <= 0)) break;
				
				// if there is any car waiting at the right bank
				else if (atLeft) {
					if (carsRight.size() > 0 && carsRight.front().arrival_t <= curr_time) {
						atLeft = 1 - atLeft;
						curr_time += t;
					} else isBankEmpty = true; // No car at banks at the moment
				}

				// if there is any car at left bank
				else {
					if (carsLeft.size() > 0 && carsLeft.front().arrival_t <= curr_time) {
						atLeft = 1 - atLeft;
						curr_time += t;
					} else isBankEmpty = true;
				}
				
				// If no car at the bank, wait for the first car to arrive
				if (isBankEmpty){
					
					// Wait till the first car arrive
					if (carsLeft.size() > 0 && carsRight.size() > 0){
						curr_time = min(carsLeft.front().arrival_t, carsRight.front().arrival_t);
					}
					
					// if no car is arriving to the left bank, wait till the car arrive at right bank.
					else if (carsLeft.size() < 1){
						curr_time = carsRight.front().arrival_t;
					}
					
					// if no car is arriving to the right bank, wait for the car from the left.
					else{
						curr_time = carsLeft.front().arrival_t;
					}
				}
			}
			
			if (debug) {
				for (int j = 0; j < m; j++) cout << carsArrivalList[j].inputNum << "  " << carsArrivalList[j].unloaded_t << endl;
				cout << endl;
			}
		}

		for (int j = 0; j < m; j++) cout << carsArrivalList[j].unloaded_t << endl;
		cout << endl;
	}
	return 0;
}

