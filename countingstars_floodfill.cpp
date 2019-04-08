// do it in dfs
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


vector<string>AL;

// up down left right
int v[4] = {-1, 1, 0, 0};
int h[4] = {0, 0, -1, 1};

void dfs(int i, int k, int rows_t, int cols_t){
	AL[i][k] = '#';
	for (int a = 0; a < 4; a++){
		int rows = i+h[a];
		int cols = k+v[a];
		if(rows >= 0 && rows < rows_t && cols >= 0 && cols < cols_t){
			if(AL[rows][cols] == '-') dfs(rows,cols,rows_t,cols_t);
		}		
	}	
}

int main() {
	fast();
//	freopen("input.txt", "r", stdin);

	int rows , cols;
	int n = 0;
	while(cin>>rows>>cols && !cin.eof()){
		n++;
		int stars = 0;
		AL.clear();
		for(int i = 0; i < rows; i++){
			string temp;
			cin >> temp;
			AL.pb(temp);
		}
		for (int i = 0; i < rows; i++){
			for (int k = 0;  k < cols; k++){
				if(AL[i][k] == '-'){
					stars++;
					dfs(i,k,rows,cols);
				}
			}
		}
		cout << "Case " << n << ": " << stars<<endl;
	}
	return 0;
}


