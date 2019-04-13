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

typedef tuple<int,int,int,int> f;
typedef vector<f> vf;
typedef vector<int> vi;
int main() {
	fast();
	freopen("input_sssp.txt", "r", stdin);
	int debugging = 0;
	int n,m,q,s;
	while(cin >> n >> m >>q >>s,(n || m || q || s)){
		vector<vf>AL(n,vf());
		while(m--){
			int a, b, t, v, d; cin >> a >> b>>t>>v>>d;
			AL[a].emplace_back(b,t,v,d);
		}
		
		for(auto &u:AL){
			sort(u.begin(),u.end());
		}
		
		vector<int>D(n,-1);
		D[s] = 0;
		
		set<pair<int,int>>ds;
		ds.insert({0,s});
		
		while(!ds.empty()){
			int node_t = (*ds.begin()).first;
			int node = (*ds.begin()).second;
			ds.erase(ds.begin());
			for (auto &next_node_info:AL[node]){
				int next_node = get<0>(next_node_info);
				int next_node_t = get<1>(next_node_info);
				int next_node_p = get<2>(next_node_info);
				int next_node_d = get<3>(next_node_info);

				// update the time for node to traverse to the next node
				bool isImpossible = false;
				if (node_t > next_node_t){
					if (next_node_p!= 0){
						while(next_node_t < node_t){
							next_node_t += next_node_p;
						}
					}
					else isImpossible = true;
				}
				// update the time when node is done traversing
				int next_time = next_node_t + next_node_d;
				if(debugging)printf("curr_node = %d curr_time = %d  next_node = %d  next_node_t = %d next_time = %d  ", node, node_t, next_node, next_node_t, next_time);
				
				// update the shorter time taken if there is any
				if (!isImpossible && (D[next_node] == -1 || next_time < D[next_node])){
					// if there is more next_node in the queue to be process, clear it.
					if (ds.count({D[next_node], next_node})){
						ds.erase(ds.find({D[next_node], next_node}));
					}
					D[next_node] = next_time;
					ds.insert({next_time,next_node});
					if(debugging)cout << "updated" <<endl;
				}
				if(debugging)cout << endl;
			}
		}
		
		while(q--){
			int r; cin >> r;
			if (D[r] == -1) cout << "Impossible" << endl;
			else cout << D[r] << endl;
		}
		cout << endl;
	}
	return 0;
}



