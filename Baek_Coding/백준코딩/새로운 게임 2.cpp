#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[13][13];		//1~num까지 이동
int num, knight;
int result = 1001;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x, y, dir;
};
info tmp;
vector<int> v[13][13];
vector<info> k;

void start() {
	int cnt = 0;
	int cx, cy, cd, nx, ny, idx, id;
	bool flag = false;
	while (1) {
		cnt++;
		if (cnt > 1000)
			break;
		//움직이기
		for (int i = 0; i < knight; i++) {
			cx = k[i].x;
			cy = k[i].y;
			cd = k[i].dir;
			vector<int> temp;
			idx = -1;
			for (int j = 0; j < v[cy][cx].size(); j++) {
				if (v[cy][cx][j] == i) {
					idx = j;
					temp.push_back(v[cy][cx][j]);
					continue;
				}
				if (idx != -1)
					temp.push_back(v[cy][cx][j]);
			}
			nx = cx + dx[cd];
			ny = cy + dy[cd];
			//밖으로 나가려는 경우x && 다음이 파란색일 때
			if (nx > 0 && ny > 0 && nx <= num && ny <= num) {
				if (arr[ny][nx] == 2) {
					nx = cx + dx[(cd + 2) % 4];
					ny = cy + dy[(cd + 2) % 4];
					//방향 바꿔놓기
					k[i].dir = (cd + 2) % 4;
					if (nx<1 || ny<1 || nx>num || ny>num)
						continue;
				}
				else {
					//아무 행동도 취하지 않음
				}
			}
			//밖으로 나가려는 경우
			else {
				nx = cx + dx[(cd + 2) % 4];
				ny = cy + dy[(cd + 2) % 4];
				//방향 바꿔놓기
				k[i].dir = (cd + 2) % 4;
			}

			if (arr[ny][nx] < 2) {
				//위의 말 전부 위치 바꿔주기
				for (int j = 0; j < temp.size(); j++) {
					id = temp[j];
					k[id].x = nx;
					k[id].y = ny;
				}
				//옮겨진 말들을 기존 위치에서 빼기
				int tt = temp.size();
				while (tt > 0) {
					v[cy][cx].pop_back();
					tt--;
				}
				if (arr[ny][nx] == 1) {
					//역순으로 만들어놓기
					reverse(temp.begin(), temp.end());
				}
				//위에 쌓기
				for (int j = 0; j < temp.size(); j++)
					v[ny][nx].push_back(temp[j]);
			}
			//4개가 겹쳐있는지 확인
			for (int m = 1; m <= num; m++) {
				for (int j = 1; j <= num; j++) {
					if (v[m][j].size() >= 4) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (flag) {
			result = cnt;
			break;
		}
	}
}

int main() {
	cin >> num >> knight;
	int x, y, dir;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	for (int i = 0; i < knight; i++) {
		cin >> y >> x >> dir;
		tmp.x = x;
		tmp.y = y;
		if (dir == 2)
			tmp.dir = 3;
		else if (dir == 3)
			tmp.dir = 0;
		else if (dir == 4)
			tmp.dir = 2;
		else
			tmp.dir = dir;
		v[y][x].push_back(i);
		k.push_back(tmp);
	}
	start();
	if (result == 1001)
		cout << -1;
	else
		cout << result;
	system("pause");
	return 0;
}