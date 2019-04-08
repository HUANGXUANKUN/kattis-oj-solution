#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

uset<int> buttons;
umap<vector<int>>pressed;
void bfs(int first_button){
	queue<int> q;
	q.push(first_button);
	vector<int>vect_temp(3600);
	vect_temp[first_button]
	pressed[vect_temp]
	
	while(q.size()){
		int top = q.front();
		q.pop();
		rep()
	}
}


int main() {
	fast();
//	freopen("input.txt", "r", stdin);
	int cases; cin >> cases;
	while (cases--){
		buttons.clear();
		int n, t; cin >> n >> t;
		rep(i,n){
			int time; cin >> time;
			buttons.insert(time);
		}
		
		// if required cooking time is zero, no button is needed to be pressed
		if(t == 0){
			cout << 0 << 0 << endl;
			continue;
		}
		
		int init_node = buttons.begin();
		bfs(init_node);
		cout << min_button << time_exceeded << endl;
		
		
	}
	return 0;
}



