#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
int arr[51][50];
int check[51][50];
int num, dir, rot_time;
int n, m, rot;
bool flag = false;		//인접한 수를 지운경우 true로 바꿈

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x;
	int y;
	int val;
};
info tmp;

void change() {
	int tot = 0;
	int cnt = 0;
	double avg;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				tot += arr[i][j];
				cnt++;
			}
		}
	}
	avg = (double)tot / cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				if (arr[i][j] < avg)
					arr[i][j] += 1;
				else if (arr[i][j] > avg)
					arr[i][j] -= 1;
			}
		}
	}
	/*cout << "평균 기준 바꾼후 상태: \n";
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
}

void bfs(queue<info> q) {
	int cx, cy, cval,ny,nx;
	queue <info> erase;
	tmp.x = q.front().x;
	tmp.y = q.front().y;
	tmp.val = q.front().val;
	erase.push(tmp);
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cval = q.front().val;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = cy + dy[i];
			nx = cx + dx[i];
			if (nx == -1) nx = m - 1;
			else if (nx == m) nx = 0;
			if (1 <= ny && ny <= n) {
				if (check[ny][nx] != 1 && arr[ny][nx] == cval) {
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cval;
					check[ny][nx] = 1;
					erase.push(tmp);
					q.push(tmp);
				}
			}
		}
	}
	if (erase.size() > 1) {
		flag = true;
		while(!erase.empty()){
			cx = erase.front().x;
			cy = erase.front().y;
			arr[cy][cx] = 0;
			erase.pop();
		}
	}
	while (!erase.empty())
		erase.pop();
}

void move(int num, int rot_time, int dir) {		//0~m-1까지 원판번호
	int temp;
	if (dir == 0) {		//시계
		for (int i = 0; i < rot_time; i++) {
			temp = arr[num][m - 1];
			for (int j = m - 1; j > 0; j--) {
				arr[num][j] = arr[num][j - 1];
			}
			arr[num][0] = temp;
		}
	}
	else if (dir == 1) {		//반시계
		for (int i = 0; i<rot_time; i++) {
			temp = arr[num][0];
			for (int j = 0; j < m-1; j++) {
				arr[num][j] = arr[num][j + 1];
			}
			arr[num][m - 1] = temp;
		}
	}
}

bool check2() {
	bool f = true;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] != 0)
				f = false;
	return f;
}
int main() {
	cin >> n >> m >> rot;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < rot; i++) {
		cin >> num >> dir >> rot_time;
		for (int j = 1; j <= n; j++) {		//회전
			if (j%num == 0) {
				if (dir == 1) {
					if (rot_time > m / 2)
						move(j, m - rot_time, 0);
					else
						move(j, rot_time, 1);
				}
				else if (dir == 0) {
					if (rot_time > m / 2)
						move(j, m - rot_time, 1);
					else
						move(j, rot_time, 0);
				}
			}
		}
		flag = false;
		for (int i = 0; i < 51; i++)
			memset(check[i], -1, sizeof(check[i]));
		queue<info> q;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < m; k++) {
				if (check[j][k] == -1 && arr[j][k] != 0) {
					tmp.x = k;
					tmp.y = j;
					tmp.val = arr[j][k];
					check[j][k] = 1;
					q.push(tmp);
					bfs(q);
					q.pop();
				}
			}
		}
		/*cout << "중복 제거 후:\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++)
				cout << arr[i][j];
			cout << endl;
		}
		cout << endl;*/
		if (check2())
			break;
		if (!flag)
			change();
	}
	int result = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < m; j++) 
			result += arr[i][j];
	cout << result;
	system("pause");
	return 0;
}