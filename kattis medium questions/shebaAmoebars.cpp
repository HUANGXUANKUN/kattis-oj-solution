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

vector<string> AL;
int visited[101][101];
int rows, cols; 

// the position change required to up, down, left, right and four corner. 
int y_diff[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int x_diff[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x){
	if(AL[y][x] == '.' || visited[y][x]) return;
	visited[y][x] = 1;
	int y_new, x_new; // (x,y) of the surrounding pixel to be explored
	// 8 directions, in clockwise starting from 9 oclock.
	rep(i,8){
		y_new = y + y_diff[i];
		x_new = x + x_diff[i];
		if (y_new >= 0 && y_new < rows && x_new >= 0 && x_new < cols){
			dfs(y_new, x_new);				
		}
	}
}

int main() {
	fast();
//	freopen("input_1.txt", "r", stdin);
    cin >> rows >> cols;
	rep(i,rows){
		string temp; cin >> temp;
		AL.pb(temp);	
	}
	
	int CC = 0;
	rep(y,rows){
		rep(x, cols){
			if(!visited[y][x] && AL[y][x] == '#'){
				CC++;
				dfs(y,x);
			}
		}
	}	
	cout << CC << endl;
}



