#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int row, col, limit;
int arr[500][500];
int dup[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, limit_life, age;
	bool state;
};
info tmp;
int main() {
	int test, tt;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col >> limit;
		memset(arr, false, sizeof(arr));
		queue<info> q;
		int cur = 0, result = 0;
		for (int i = 200; i < 200 + row; i++) {
			for (int j = 200; j < 200 + col; j++) {
				cin >>arr[i][j];
				if (arr[i][j] > 0) {
					tmp.x = j;
					tmp.y = i;
					tmp.limit_life = arr[i][j];
					tmp.age = 0;
					tmp.state = false;
					result++;
					q.push(tmp);
				}
			}
		}
		vector<info> v;
		while (cur < limit) {
			cur++;
			int len = q.size();
			for (int i = 0; i < len; i++) {
				int cx = q.front().x;
				int cy = q.front().y;
				int cl = q.front().limit_life;
				int cs = q.front().state;
				int ca = q.front().age;
				q.pop();
				if (!cs) {		//��Ȱ��ȭ
					tmp.y = cy;
					tmp.x = cx;
					tmp.limit_life = cl;
					tmp.state = false;
					if (ca + 1 == cl) {		//Ȱ��ȭ ���·� ����
						tmp.age = 0;
						tmp.state = true;						
						q.push(tmp);
					}
					else {				//���� ��Ȱ��ȭ ����
						tmp.age = ca + 1;
						q.push(tmp);
					}
				}
				else if (cs) {		//Ȱ��ȭ
					if (ca == 0) {
						for (int k = 0; k < 4; k++) {
							int nx = cx + dx[k];
							int ny = cy + dy[k];
							if (arr[ny][nx] != 0) continue;		//���� ��, or ���� �̹� �ִ� ��
							if (dup[ny][nx] != 0) {		//�ٸ��� �ɾ��� ����
								if (dup[ny][nx] < cl) {
									tmp.x = nx;
									tmp.y = ny;
									tmp.limit_life = cl;
									v.push_back(tmp);
									dup[ny][nx] = cl;		//�ڽź��� ���� ��� �ڽ��� �ɴ°ŷ� �ٲ۴�.
								}
							}
							else if (dup[ny][nx] == 0) {
								dup[ny][nx] = cl;
								tmp.x = nx;
								tmp.y = ny;
								tmp.limit_life = cl;
								v.push_back(tmp);
								result++;
							}
						}
					}
					if (ca + 1 == cl) {		//�Ҹ�
						result--;
					}
					else {
						tmp.x = cx;
						tmp.y = cy;
						tmp.age = ca + 1;
						tmp.limit_life = cl;
						tmp.state = cs;
						q.push(tmp);
					}
				}
			}
			for (int i = 0; i < v.size(); i++) {
				int tx = v[i].x;
				int ty = v[i].y;
				if (dup[ty][tx] != v[i].limit_life) continue;
				tmp.x = tx;
				tmp.y = ty;
				tmp.age = 0;
				tmp.limit_life = dup[ty][tx];
				tmp.state = false;
				q.push(tmp);
				arr[ty][tx] = dup[ty][tx];
				dup[ty][tx] = 0;
			}
			v.clear();
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}