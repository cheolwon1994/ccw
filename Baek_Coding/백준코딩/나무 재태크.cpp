#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
/********************************************************
x,y,나이(복수 가능), 영양분

********************************************************/

int land[11][11];		//초기에 5의 영양분을 갖고 시작
int nut[11][11];		//겨울에 추가해주는 영양분 수
int row, tree_num, year;
long long result = 0;
vector <int> t[11][11];			//나이를 가지는 나무배열
vector <int> dt[11][11];
int x[8] = { 0,1,1,1,0,-1,-1,-1 };
int y[8] = { -1,-1,0,1,1,1,0,-1 };

void spring() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= row; j++) {
			if (t[i][j].size()) {
				int dead = 0;
				vector<int> v;
				sort(t[i][j].begin(), t[i][j].end());
				for (int k = 0; k < t[i][j].size(); k++) {
					int t_age = t[i][j][k];
					if (land[i][j] >= t_age) {
						land[i][j] -= t_age;
						v.push_back(t_age + 1);
					}
					else
						dead += (t_age / 2);					
				}
				t[i][j].clear();
				for (int k = 0; k < v.size(); k++)
					t[i][j].push_back(v[k]);
				land[i][j] += dead;
			}
		}
	}
}
void autumn() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= row; j++) {
			if (t[i][j].size()) {
				for (int k = 0; k < t[i][j].size(); k++) {
					if (t[i][j][k] % 5 == 0) {
						int nx, ny;
						for (int l = 0; l < 8; l++) {
							nx = j + x[l];
							ny = i + y[l];
							if (nx >= 1 && ny >= 1 && nx <= row && ny <= row) {
								t[ny][nx].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= row; j++) 
			land[i][j] += nut[i][j];		
}
int main() {
	cin >> row >> tree_num >> year;
	//초기화
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= row; j++) {
			cin >> nut[i][j];
			land[i][j] = 5;
		}
	int a, b, c;
	for (int i = 0; i < tree_num; i++) {
		cin >> a >> b >> c;
		t[a][b].push_back(c);
	}
	while (year > 0) {
		spring();
		autumn();
		winter();
		year--;
	}
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= row; j++) 
			result += t[i][j].size();
		
	cout << result;
	system("PAUSE");
	return 0;
}
