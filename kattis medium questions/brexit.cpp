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

vector<set<int>> AL(200001);
vector<int>o_size(200001);

bool is_leaving(int a){
	return (AL[a].size() <= (o_size[a] / 2));
}
void check(int L){
	queue<int> q;
	q.push(L);
	while(q.size()){
		int q_front = q.front();
		q.pop();
		if (is_leaving(q_front)|| (L == q_front)){
			for(auto&v:AL[q_front]){
				q.push(v);
			}
			set<int> &set_1 = AL[q_front];
			for (auto&a:set_1){
				// if q_front is found in any set in AL, remove from the set
				AL[a].erase(q_front); 
			}
			AL[q_front].clear();
		}
	}
}
int main() {
	fast();
	freopen("input_brexit.txt", "r", stdin);
	int C , P, X,L;
	cin >> C >> P >> X >> L;
	rep(i, P){
		int a, b;
		cin >> a>>b;
		AL[a].insert(b);
		AL[b].insert(a);
	}
	
	rep1(i, C){
		o_size[i] = AL[i].size();
	}
	check(L);
	if(is_leaving(X)){
		cout << "leave" << endl;
	}
	else cout << "stay" << endl;
	return 0;
}



