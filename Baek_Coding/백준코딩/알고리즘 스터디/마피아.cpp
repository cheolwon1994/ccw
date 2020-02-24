#include <iostream>
#include <algorithm>
using namespace std;
int num, result = 0, mafia;
int score[16];
bool dead[16] = { false, };
int arr[16][16];
bool finish = false;
void game(int remain, int night) {
	if (finish) return;
	if (remain == 1 || dead[mafia]) {
		result = max(result, night);
		if(remain==1)	finish = true;
		return;
	}
	if (remain % 2 == 1) {				//³·
		int idx = -1;
		int maxi = -1;
		for (int i = 0; i < num; i++) {
			if (score[i] > maxi && !dead[i]) {
				maxi = score[i];
				idx = i;
			}
		}
		dead[idx] = true;
		game(remain - 1, night);
		dead[idx] = false;	
	}
	else if (remain % 2 == 0) {		//¹ã
		for (int i = 0; i < num; i++) {
			if (i != mafia && !dead[i]) {
				dead[i] = true;
				for (int j = 0; j < num; j++)
					if (j != i && !dead[j])
						score[j] += arr[i][j];
				game(remain - 1, night + 1);
				dead[i] = false;
				for (int j = 0; j < num; j++)
					if (j != i && !dead[j])
						score[j] -= arr[i][j];
			}
		}		
	}
}

int main() {
	int remain;
	cin >> num;
	remain = num;
	for (int i = 0; i < num; i++)
		cin >> score[i];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	cin >> mafia;
	if (num == 1) result = 0;
	game(remain, 0);
	cout << result;
	system("pause");
	return 0;
}