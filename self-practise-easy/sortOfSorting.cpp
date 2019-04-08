#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string str[200];
	int N = 1;
	int num;
	while (N <= 500 and cin >> n){
		if (n == 0) 
			break;
		num = n;
		for (int i = 0; i < n; i++){
			cin >> str[i];
		}
		
		bool swapped;
		do{
			swapped = false;
			for (int i = 0; i < num-1; i++){
				if(str[i][0] > str[i+1][0]){
					swap(str[i], str[i+1]);
					swapped = true;
				}
				else if (str[i][0] == str[i+1][0]){
					if (str[i][1] > str[i+1][1])
						swap(str[i], str[i+1]);
						swapped = true;						
				}
			}
			num--;
		}
		while (swapped);
		
		for (int i = 0; i < n; i++){
			printf("%s\n", str[i].c_str());
		}
		printf("\n");	
	
		N++;
	}
	return 0;
}
