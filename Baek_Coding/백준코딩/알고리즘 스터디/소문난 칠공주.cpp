#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
char arr[5][5];
bool check[5][5];
struct info {
	int x, y;
	char c;
};
info tmp;
vector<info> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int result = 0;
set<string>ss;
void dfs(int y, int x, int cnt) {
	if (cnt == 7) {
		int temp = 0;
		for (int i = 0; i < 7; i++) 
			if (v[i].c == 'S')
				temp++;
		if (temp >= 4) {
			vector<int> tt;
			for (int i = 0; i < v.size(); i++)
				tt.push_back(v[i].y * 5 + v[i].x);
			sort(tt.begin(), tt.end());
			string str="";
			std::string s;
			for (int i = 0; i < tt.size(); i++) {
				s = std::to_string(tt[i]);
				str += s;
			}
			ss.insert(str);
		}
		return;
	}
	int cx, cy, nx, ny;
	for (int j = 0; j < v.size(); j++) {
		cx = v[j].x;
		cy = v[j].y;
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && !check[ny][nx]) {
				if (ny * 5 + nx > y * 5 + x) {
					tmp.x = nx;
					tmp.y = ny;
					tmp.c = arr[ny][nx];
					v.push_back(tmp);
					check[ny][nx] = true;
					dfs(y, x, cnt + 1);
					v.pop_back();
					check[ny][nx] = false;
				}
			}
		}
	}
}

int main() {
	string str;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < 5; j++)
			arr[i][j] = str[j];
	}
	for(int i=0;i<5;i++)
		for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++)
					memset(check[k], false, sizeof(check[k]));
				v.clear();
				tmp.x = j;
				tmp.y = i;
				tmp.c = arr[i][j];
				check[i][j] = true;
				v.push_back(tmp);
				dfs(i,j,1);		
		}
	cout << ss.size();
	system("pause");
	return 0;
}