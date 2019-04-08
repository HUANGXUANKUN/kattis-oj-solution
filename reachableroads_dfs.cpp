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
vector<vector<int>>AL;
uset<int> visited;
void dfs(int i){
	visited.insert(i);
	for(auto&v:AL[i]){
		if(!visited.count(v)){
			dfs(v);
		}
	}
}
int main() {
	fast();
//	freopen("input_reachable.txt", "r", stdin);
	int n; cin >> n;
	while(n--){
		int a; cin >> a;
		int b; cin >> b;
		visited.clear();
		AL.assign(a, vector<int>());
		for (int i = 0; i < b; i++){
			int lhs, rhs;
			cin >> lhs >> rhs;
			AL[lhs].pb(rhs); 
			AL[rhs].pb(lhs); 
		}
		int cc = 0;
		for(int i = 0; i < a; i++){
			if (!visited.count(i)){
				cc++;
				dfs(i);
			}
		}
		cout << cc-1 << endl;
	}
}


