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
uset<string> visited;
list<string> files;
void dfs(string str){
	// if visited
    if(visited.count(str) > 0) return;
    visited.insert(str);
    for(auto&v:AL[str]){
        dfs(v);
    }
    files.push_front(str);
}

int main() {
    fast();
//    freopen("input_dependencies.txt", "r", stdin);
    int n; cin >> n; cin.get();
    while(n--){
        string line, temp, token;
        getline(cin,line);
        istringstream iss(line);
        iss >> temp;
        temp.pop_back();
//         debug(temp);
        while(iss >> token){
            AL[token].pb(temp);
//             debug(token);
        }
    }
    
    string temp; cin >> temp;
    dfs(temp);
    for(auto&v:files)
        cout << v << endl;
    return 0;
}


