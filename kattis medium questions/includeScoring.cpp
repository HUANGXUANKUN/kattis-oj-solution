#include <bits/stdc++.h>
using namespace std;
struct score{
	int solved;
	long penalty;
	int lastTime;
	int extraPoint;
	int input_pos;
	int rank;
	int score = 0; 
};

int compare(score a, score b);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input2.txt", "r", stdin);
	int n;
	cin >> n;
	score data[2000];
	
	// input data
	for (int i = 0; i < n; i++){
		cin >> data[i].solved >> data[i].penalty >> data[i].lastTime >> data[i].extraPoint;
		data[i].input_pos = i;
	}	
	
	// rank list
	for (int i = 1; i < n; i++){
		score temp = data[i];
		int j = i;
		while (j-1 >= 0){
		 	int result = compare(temp, data[j-1]);
//			printf("compare %d and %d result = %d\n", temp.input_pos, data[j-1].input_pos, result);
		 	if (result == 1 || result == 0){ 
				data[j] = data[j-1];
				j--;
			}
			else if (result == -1){
				break;
			}
		}
		
		data[j] = temp;		
	}
	
	int rank_delay = 0;
	for (int i = 0; i < n; i++){
		if((i-1 >= 0) && (data[i].solved == data[i-1].solved && 
			data[i].penalty == data[i-1].penalty && data[i].lastTime == data[i-1].lastTime)){
				rank_delay++;
				data[i].rank = i - rank_delay;				
		}
		
		else {
			data[i].rank = i;
			rank_delay = 0;
		}
	}

	int score_list[30] = {100, 75, 60, 50, 45, 40,
	36, 32, 29, 26, 24, 22,
	20, 18, 16, 15, 14, 13,
	12, 11, 10, 9, 8, 7, 
	6, 5, 4, 3, 2, 1};
	
	for (int i = 0; i < n; i++){
		if (i < 30){
			data[i].score = score_list[i];
		}
	}
	
	for (int i = 0; i < n && i < 30; i++){
		int k = i;
		int same_rank = 0;
		while ((data[k].rank == data[k+1].rank) && (k+1 < n)){
			same_rank++;
			k++;
		}
		if (same_rank > 0){
//			printf("samerank is %d\n", same_rank);
			double total_score = 0;
			double share_score;
			int share_score2 = 0;
			for (int j = i; j <= k; j++){
				total_score += data[j].score;
			}
			if (total_score != 0){
				share_score = (double)total_score / (same_rank+1);
				if (((share_score - (int)share_score)) > 0.0001){
					share_score2 =ceil(share_score);
				}
				else{
					share_score2 = round(share_score);
				}
			}
//			printf("share_score = %d\n", share_score);
			for (int j = i; j <= k; j++) data[j].score = share_score2;
		}
		
		i = k;
	}
	
//	printf("********************************************************\n");
//	for (int i = 0; i <n; i++){
//		printf("rank is = %d score is %d       %d %d %d %d %d\n", data[i].rank + 1, data[i].score, data[i].solved, data[i].penalty, data[i].lastTime, data[i].extraPoint, data[i].input_pos );
//	}
	for (int i = 1; i < n; i++){
		score temp = data[i];
		int j;
		for (j = i-1; j >= 0 && data[j].input_pos > temp.input_pos; j--){
			data[j+1] = data[j];
		}
		data[j+1] = temp;

	}

	for (int i = 0; i <n; i++){
		if(data[i].extraPoint){
			data[i].score++;
		}
		printf("%d\n",data[i].score);

	}
//	printf("********************************************************\n");
//	for (int i = 0; i <n; i++){
//		printf("rank is = %d score is %d       %d %d %d %d %d\n", data[i].rank + 1, data[i].score, data[i].solved, data[i].penalty, data[i].lastTime, data[i].extraPoint, data[i].input_pos );
//	}
	return 0;
}

int compare(score a, score b){
	if (a.solved > b.solved)
		return 1;
	else if (a.solved < b.solved)
		return -1;
		
	else {
		if (a.penalty < b.penalty)
			return 1;
		else if (a.penalty > b.penalty)
			return -1;
		else {
			if (a.lastTime < b.lastTime)
				return 1;
			else if (a.lastTime > b.lastTime)
				return -1;
			else
				return 0;
		}
	}
}

