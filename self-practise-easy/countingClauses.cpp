#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	string X[m];
	int input;
	int count = m;
	stringstream str_num;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &input);
//			str_num << input << endl; //c98
//			X[i] += str_num.str(); //c98
			X[i] += to_string(input); //c11
		}
	}
	for (int i = 0; i < m; i++)
//		cout << "str" << i+1 << "is " << X[i] << endl;
//		printf("str%d is %s\n", i+1, X[i].c_str());
		for (int j = (i+1); j < m; j++){
			if (X[i] == X[j])
				count--;
		}
	if (count >= 8)
		printf("satisfactory\n");
	else
		printf("unsatisfactory\n");

	return 0;
}
