#include <bits/stdc++.h>
using namespace std;

int main(){
	int room[101] = {0};
	int r, n;
	cin >> r >> n;
	int room_no;
	while (cin >> room_no){
		room[room_no] = 1;
	}
	
	if (r == n)
		printf("too late");
	else {
		int i = 1;
		while (room[i] == 1){
			i++;
		}
		printf("%d", i);
	}
	return 0;
}
