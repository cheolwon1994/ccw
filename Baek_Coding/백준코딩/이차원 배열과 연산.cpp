#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

int r, c, k;
int row, col;
bool finish = false;
int result = 0;
int f[101][101];
int arr[101][101];

struct info {
	int val;
	int many;
};
info tmp;
vector <info> v;

int insert(vector <info> v, int a) {
	int t = v.size();
	int idx = 0;
	int mini;
	int cnt = 1;
	/*for (int i = 0; i < v.size(); i++)
		cout << v[i].val <<"  "<< v[i].many << endl;
	cout << endl;*/
	memset(arr[a], 0, sizeof(arr[a]));
	while(2*t+1>cnt) {
		mini = 101;
		for (int j = 0; j < t; j++) {
			if (mini > v[j].many) {
				mini = v[j].many;
				idx = j;
			}
		}
		arr[a][cnt++] = v[idx].val;
		arr[a][cnt++] = mini;
		v[idx].val = 200;
		v[idx].many = 200;
	}
	return cnt-1;
}

int insert2(vector <info> v, int b) {
	int t = v.size();
	int idx = 0;
	int mini;
	int cnt = 1;
	for (int i = 1; i < 101; i++)
		arr[i][b] = 0;
	while (2 * t + 1 > cnt) {
		mini = 101;
		for (int i = 0; i < t; i++) {
			if (mini > v[i].many) {
				mini = v[i].many;
				idx = i;
			}
		}
		arr[cnt++][b] = v[idx].val;
		arr[cnt++][b] = mini;
		v[idx].val = 200;
		v[idx].many = 200;
	}
	return cnt - 1;
}

//빈도를 찾아주는 함수-> R전용
void freqR() {
	memset(f, 0, sizeof(f));
	//r
	int longest = -1;
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= col; j++) 
			f[i][arr[i][j]]++;
	for (int i = 1; i <= row; i++) {
		v.clear();
		for (int j = 1; j < 101; j++) {
			if(f[i][j]!=0){
				tmp.val = j;
				tmp.many = f[i][j];
				v.push_back(tmp);
			}
		}
		longest = max(longest,insert(v,i));
	}
	col = longest;
	/*for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= longest; j++)
			cout << arr[i][j];
		cout << "\n";
	}*/
}

void freqC() {
	memset(f, 0, sizeof(f));
	int longest = -1;
	for (int j = 1; j <= col; j++) 
		for (int i = 1; i <= row; i++)
			f[j][arr[i][j]]++;
	
	for (int j = 1; j <= col; j++) {
		v.clear();
		for (int i = 1; i < 101; i++) {
			if (f[j][i] != 0) {
				tmp.val = i;
				tmp.many = f[j][i];
				v.push_back(tmp);
			}
		}
		longest = max(longest, insert2(v, j));
	}
	row = longest;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin >> r >> c >> k;
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++) 
			cin >> arr[i][j];		 
		
	row = col = 3;

	while (!finish) {
		if (arr[r][c] == k)
			break;
		if (row >= col)
			freqR();
		else
			freqC();

		result++;
		if (result > 100) {
			result = -1;
			break;
		}
	}

	cout << result;
	system("PAUSE");
	return 0;
}