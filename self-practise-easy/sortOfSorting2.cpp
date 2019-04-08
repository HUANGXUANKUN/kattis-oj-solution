#include <bits/stdc++.h>
using namespace std;

//bool isNameGreater(string a, string b){
//	
//	if(a[0] > b[0]){
//		return true;
//	}
//	
//	else if (a[0] == b[0]){
//		if (a[1] > b[1])
//			return true;
//	}
//	
//	return false;
//}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string str[200];
	int N = 1;
	string temp;
	while (N <= 500 and cin >> n){
		if (n == 0) 
			break;
			
		for (int i = 0; i < n; i++){
			cin >> str[i];
		}
		int j;
		for (int i = 1; i < n; i++){
			temp = str[i];
			for(j = i-1; j >= 0 && ((str[j][0] > temp[0]) || (str[j][0] == temp[0] && str[j][1] > temp[1])); j--)
				str[j+1] = str[j];
			
			str[j+1] = temp;
			
		} 
		
		for (int i = 0; i < n; i++){
			printf("%s\n", str[i].c_str());
		}
		printf("\n");	
	
		N++;
	}
	return 0;
}
