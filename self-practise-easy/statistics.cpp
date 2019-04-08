#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, caseNo = 1;
  while (cin >> n) {
    int X[10000];
    for (int i = 1; i <= n; i++)
      cin >> X[i];
    int minV = 1e9, maxV = -1e9;
    for (int i = 1; i <= n; i++) {
      int v = X[i];
      minV = min(minV, v);
      maxV = max(maxV, v);
    }
    cout << "Case " << caseNo++ << ": " << minV << " " << maxV << " " << (maxV-minV) << endl;
  }
  return 0;
}
