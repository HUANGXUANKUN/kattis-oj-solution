// use dfs with closed loop detection
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

umap<string, vector<string>> AL;
umap<string,int> visited;
bool dfs(string str){
	visited[str] = 1;
	for (auto&v:AL[str]){
		if (!visited.count(v)){
			if(dfs(v)) return true;
		}
		else if (visited[v]==1){
			return true;
		}
	}
	
	// end point
	visited[str] = 2;
	return false;
}
int main() {
	fast();
//	freopen("input_runningmom.txt", "r", stdin);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		AL[a].pb(b);
	}
	string toFind;
	while(cin >> toFind && !cin.eof()){
		visited.clear();
		bool isSafe = dfs(toFind);
		if(isSafe) cout << toFind << " " << "safe" << endl;
		else cout << toFind << " " << "trapped" << endl;
	}
	return 0;
}


