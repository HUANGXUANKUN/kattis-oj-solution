#include <bits/stdc++.h>
using namespace std;

class Hand{
	public:
		int curr_state; // State of the hand, such as folded, spilted, palm down and removed.
		int playerNum;
		int init_state;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("coconutSplat_input.txt", "r", stdin);
	int s; cin >> s;
	int n; cin >> n;
	int playerLeft = n;
	list<Hand> handList;
	bool debug = false;
	for (int i = 0; i<n; i++)
	{
		Hand temp;
		temp.curr_state = 0;
		temp.playerNum = i+1;
		temp.init_state = 0;
		handList.push_back(temp);
	}

	int curr_index = 0;
	
	while(handList.size() > 1){
		int step = (s-1) % handList.size();
		curr_index = (curr_index + step) % handList.size();
		auto temp_iter = handList.begin(); // create a pointer to the last touched hand.
		advance(temp_iter, curr_index);
		if (debug) cout << "Current index_i = " << curr_index << endl;
		
		// check if last touched hand is folded
		if (temp_iter->curr_state == 0)
		{
			temp_iter->curr_state = 1; // Update the state of the last touched hand to "splited"
			Hand temp; // Create a new fist
			temp.curr_state = 1; // Initialize state of the new fist to "splited"
			temp.playerNum = temp_iter->playerNum; // Initialize the player number whom the fist is belonged.
			temp.init_state = 1;
			
			auto next_iter = ++temp_iter;
			handList.insert(next_iter, temp); // Insert the new fist to the list.
		}		
		
		else if (temp_iter->curr_state == 1)
		{
			temp_iter->curr_state = 2;
			if (curr_index+1 <= handList.size()-1) curr_index++;
			else curr_index = 0; 
		}
		
		else if (temp_iter->curr_state == 2)
		{
			temp_iter->curr_state = 3;
			handList.erase(temp_iter);
			if (curr_index > handList.size()-1) curr_index = 0;			
		}
		
		else
		{
			temp_iter->curr_state = 4;
			handList.erase(temp_iter);
		}		
		
		if(debug){
			auto start = handList.begin();
			cout << "Current_index is "<< curr_index << endl;
			for (int i = 0; i < handList.size(); i++){
				cout << " element's state' is " << start->curr_state;
				cout << "    playerNum is " << start->playerNum << endl;
				++start;  
			}			
			cout << endl;
		}
	}
	
	cout << handList.front().playerNum;
	return 0;
}

