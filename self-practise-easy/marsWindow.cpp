#include <bits/stdc++.h> // to include everthing
using namespace std; // dangerous

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int y; scanf("%d", &y);
  int cur_m = 3, cur_y = 2018;
  while (cur_y < y) {
    cur_y += 2, cur_m += 2; // 26 months = 2 years+2 months
    if (cur_m >= 12) // overshot
      cur_y++, cur_m %= 12; // back to Jan
  }
  printf((cur_y == y) ? "yes\n" : "no\n");
  return 0;
}	
