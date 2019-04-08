#include <bits/stdc++.h>
using namespace std;

struct Researcher{
	int arrive_t;
	int leave_t;
};

struct Comp{
	bool operator() (Researcher& a, Researcher& b){
		if (a.arrive_t == b.arrive_t) return (a.leave_t > b.leave_t);
		else return (a.arrive_t > b.arrive_t);
	}
}myComp;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("assigningWorkstations_input2.txt", "r", stdin);
	
	int debug = 0;
	
	int N; cin >> N;
	int lockTime; cin >> lockTime;
	int unlockedNum = 0; // Number of computer being unlocked;
	
	vector<Researcher> timetable;
	priority_queue<int, vector<int>, greater<int>> lockTimeList;
	
	for (int i = 0; i < N; i++){
		Researcher temp;
		int stay_t;
		cin >> temp.arrive_t;	
		cin >> stay_t;	
		temp.leave_t = temp.arrive_t + stay_t;
		timetable.push_back(temp);
	}
	
	sort(timetable.begin(), timetable.end(), myComp);
	
	for (int i = 0; i < N; i++){
		bool isPush = false;
		while(!isPush){
			// if no com is unlocked
			if (lockTimeList.empty()){
				if(debug) cout << "list empty, add a com with lock time at " << timetable.back().leave_t + lockTime << endl; 
				lockTimeList.push(timetable.back().leave_t+lockTime);
				timetable.pop_back();
				unlockedNum++;
				isPush = true;
			}	
			
			// if there is computer unlocked
			else if(timetable.back().arrive_t <= lockTimeList.top()){
				// if the first computer that will be free is still in use
				if(timetable.back().arrive_t < lockTimeList.top()-lockTime){
					if(debug) cout << "com in use, add a com with lock time at " << timetable.back().leave_t + lockTime << endl; 
					unlockedNum++;
				}
				// else if there is any free computer, use it and update its lock time in the priority queue.
				else{
					if(debug) cout << "com is free, update the com lock time to " << timetable.back().leave_t + lockTime << endl;
					lockTimeList.pop();		
				}
				
				isPush = true;	
				lockTimeList.push(timetable.back().leave_t + lockTime);
				timetable.pop_back();
			}
			
			// else if the arrival time is after the lock time, clear the locked computers from the list.
			else{
				while(!lockTimeList.empty() && timetable.back().arrive_t > lockTimeList.top()){
					if(debug) cout << "com is locked, remove the com locked at " << lockTimeList.top() << endl;
					lockTimeList.pop();
				}
			}		
		}
		if(debug) cout << "unlocked num of computer is " << unlockedNum << endl;
		if(debug) cout << "------------------------------------" << endl;
	}
	cout << N-unlockedNum << endl;
	return 0;
}

