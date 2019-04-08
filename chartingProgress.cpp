#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string line, line2;
	string firstLine;
	int lineLen;
	string X[101];
	int log[100];
	int i;
	int back;
	char c;
	int star;
	while (getline(cin,firstLine)) {
		i = 1;
		back = 0;
		memset(log, -1, sizeof(log));
		if (!firstLine.empty()){
			X[0] = firstLine;
			lineLen = firstLine.size();
		}
		else break;
		
		while (getline(cin, X[i]) && !X[i].empty()) {
			i++;
		}
		
		for (int y = 0; y < i; y++){
			line = X[y];
			star = 0;
			for (int x = 0; x < lineLen ; x++){
				if (line[x] == '*'){
					star++;
				}			
			}
			for (int x = 0; x < lineLen - star - back; x++){
				printf(".");
			}
			
			for (int x = lineLen - star - back; x < lineLen - back; x++){
				printf("*");
			}
			
			for (int x = lineLen - back; x < lineLen; x++){
				printf(".");
			}
			back += star;
			printf("\n");
		}
	}
 	return 0;	
}

