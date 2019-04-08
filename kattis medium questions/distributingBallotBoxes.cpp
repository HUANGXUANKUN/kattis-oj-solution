#include <bits/stdc++.h>
using namespace std;

// Practise writting class templete
class City {
	public:
		int population;
		int box_n = 1;
		int box_size;
		
		// Initializing population and box_size
		City(int p){
			population = p;
			box_size = p;
		}
		void add_box(){
			box_n++;
			box_size = int(ceil((double)population/box_n));		
		}
};

// A comparator
class ComparisonClass{
	public:
		bool operator() (City a, City b){
			return(a.box_size < b.box_size);
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("distributingBallotBoxes_input.txt", "r", stdin);

	int N; // N0. cities
	int B; // No. boxes
	int debug = 0; // if executing debugging code
	while (cin>>N && cin>>B && N!=-1 && B!= -1) {
		priority_queue<City, vector<City>, ComparisonClass> cities;
		for (int i = 0; i < N; i++) {
			int p; cin >> p;
			City temp(p);
			cities.push(temp);
		}
		
		for (int i = 0; i < B-N; i++){
			City temp = cities.top();
			cities.pop();
			temp.add_box();
			cities.push(temp);
		}
		// Debugging 
		if (debug){
			for (int i = 0; i < N; i++) {
				cout << cities.top().population << " ";
				cout << cities.top().box_n << " ";
				cout << cities.top().box_size << endl;
				cities.pop();
			}
			cout <<"---------"<< endl;
		}
		
		cout<<cities.top().box_size<<endl;
	}
	return 0;
}

