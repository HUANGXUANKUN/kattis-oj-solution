#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
	bool debug = false;
    int N;
    cin >> N;
    string str;
    int s, x, len;
    vector<int> R;
    vector<int> B;

    for (int i = 0; i < N; i++){
        len = 0;
        R.clear();
        B.clear();
        
        cin >> s;
        for (int k = 0; k < s; k++){
            cin >> str;
            if (str.back() == 'R'){
                stringstream substr(str.substr(0,-1));
                substr >> x;
                R.push_back(x);
            }
            else if (str.back() == 'B'){
                stringstream substr(str.substr(0,-1));
                substr >> x;
                B.push_back(x);
            }
        }
        
        
        sort(R.begin(), R.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        int max_loops = min(R.size(), B.size());
        
        if (debug) {
            printf("R vector: ");
            for (int u = 0; u < R.size(); u++){
                printf("%d ", R[u]);
            }
            cout << endl;
            
            printf("B vector: ");
            for (int u = 0; u < B.size(); u++){
                printf("%d ", B[u]);
            }
            printf("\n");
            
            printf("max_loop = %d, R.size = %d, B.size = %d\n", max_loops, R.size(), B.size());
        }
        
        for (int k = 0; k < max_loops; k++){
            len += R[k];
            len += B[k];
        }
        len = len - max_loops*2;
        if (len < 0) len = 0;
        cout <<"Case #"<< i+1 << ": " << len << endl;

    }
    return 0;
}
