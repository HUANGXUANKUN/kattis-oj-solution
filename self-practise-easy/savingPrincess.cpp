#include <bits/stdc++.h> // to include everthing
using namespace std; // dangerous

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N, Y; cin >> N >> Y;
  bool found[110]; memset(found, false, sizeof found);
  for (int i = 0; i < Y; i++) {
    int k; cin >> k;
    found[k] = true;
  }
  int X = 0;
  for (int i = 0; i < N; i++)
    if (!found[i])
      cout << i << endl;
    else
      X++;
  cout << "Mario got " << X << " of the dangerous obstacles.\n";
  return 0;
}

