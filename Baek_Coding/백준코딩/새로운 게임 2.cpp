#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[13][13];		//1~num���� �̵�
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
		//�����̱�
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
			//������ �������� ���x && ������ �Ķ����� ��
			if (nx > 0 && ny > 0 && nx <= num && ny <= num) {
				if (arr[ny][nx] == 2) {
					nx = cx + dx[(cd + 2) % 4];
					ny = cy + dy[(cd + 2) % 4];
					//���� �ٲ����
					k[i].dir = (cd + 2) % 4;
					if (nx<1 || ny<1 || nx>num || ny>num)
						continue;
				}
				else {
					//�ƹ� �ൿ�� ������ ����
				}
			}
			//������ �������� ���
			else {
				nx = cx + dx[(cd + 2) % 4];
				ny = cy + dy[(cd + 2) % 4];
				//���� �ٲ����
				k[i].dir = (cd + 2) % 4;
			}

			if (arr[ny][nx] < 2) {
				//���� �� ���� ��ġ �ٲ��ֱ�
				for (int j = 0; j < temp.size(); j++) {
					id = temp[j];
					k[id].x = nx;
					k[id].y = ny;
				}
				//�Ű��� ������ ���� ��ġ���� ����
				int tt = temp.size();
				while (tt > 0) {
					v[cy][cx].pop_back();
					tt--;
				}
				if (arr[ny][nx] == 1) {
					//�������� ��������
					reverse(temp.begin(), temp.end());
				}
				//���� �ױ�
				for (int j = 0; j < temp.size(); j++)
					v[ny][nx].push_back(temp[j]);
			}
			//4���� �����ִ��� Ȯ��
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