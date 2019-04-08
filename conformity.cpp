#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	map<string,int>ds_1;
	while(n--){
		string a,b,c,d,e;
		cin >> a >> b>> c>> d>> e;
		vector<string>ds({a,b,c,d,e});
		sort(ds.begin(),ds.end());
		string temp = "";
		for(int i = 0;i<5;i++){
			temp += ds[i];
		}
		ds_1[temp]++;
	}
	int maxV = -1;
	int maxCount = 0;
	for(auto&v:ds_1){
		if (v.second > maxV){
			maxV = v.second;
			maxCount = maxV;
		}
		else if (v.second == maxV)
			maxCount+= maxV;
	}

	cout << maxCount <<  endl;
	

}

