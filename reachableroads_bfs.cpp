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

vector<vector<int>> AL;
uset<int> visited;

void bfs(int i){
	queue<int>q;
	q.push(i);
//	debug(i);
	visited.insert(i);
	while(!q.empty()){
		auto a = q.front();
		q.pop();
		for(auto&u:AL[a]){
			if(!visited.count(u)) {
				visited.insert(u);
//				debug(u);
				q.push(u);
			}
		}
	}	
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//	freopen("input_reachable.txt", "r", stdin);
	int n;
	cin >> n;
	while(n--){
		int cities, r;
		cin >> cities >> r;
//		debug(cities);
//		debug(r);
		int cc = 0;
		visited.clear();
		AL.clear();
		AL.assign(cities, vector<int>());
		for(int i = 0; i < r; i++){
			int a, b;
			cin >> a >> b;
			AL[a].pb(b);
			AL[b].pb(a);
		}
		for(int i = 0; i < cities; i++){
			if(!visited.count(i)){
				cc++;
				bfs(i);
			}
		}
		cout << cc-1 << endl;
	}
	return 0;
}


