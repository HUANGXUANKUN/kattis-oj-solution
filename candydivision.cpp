#include <bits/stdc++.h>
using namespace std;

typedef long long ll
const double error = 0.000001;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	long long N;
	cin >> N;
	double temp = sqrt(N);
	long long sqrt_N = floor(temp+1);
	
	set<long long>ds;
	for (long long i = 1; i < sqrt_N; i++){
		long long r = N % i;
		long long ans = N/i;

		if (r == 0){
			ds.insert(ans);
			ds.insert(i);
		}
	}
	
	for(auto&v:ds){
		cout << v-1 <<" ";
	}
	

}

