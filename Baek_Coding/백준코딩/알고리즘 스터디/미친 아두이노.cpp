#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
int dy[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
struct info {
	int x, y;
	bool crash;
};
info tmp;
int row, col, mx, my;		//��,��,�� �Ƶ��̳��� x,y��
char arr[101][101];
int check[101][101];		//�Ű��� ��ġ�� � idx�� �Ƶ��̳밡 �ִ��� Ȯ��
vector<info> v;		//��ģ�κ��� ��ġ
bool finish = false;

void mv() {		//��ģ �Ƶ��̳� �̵�
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = -1;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].crash) {		//�ر����� ���� �Ƶ��̳�
			int cx = v[i].x;
			int cy = v[i].y;
			arr[cy][cx] = '.';
			if (mx > cx) {		//��ģ �Ƶ��̳밡 �� ���� 1,4,7���⿡ ��ġ�� ���. 
				if (my < cy) {		//1
					v[i].x -= dx[1];
					v[i].y -= dy[1];
				}
				else if (my == cy) {		//4
					v[i].x -= dx[4];
					v[i].y -= dy[4];
				}
				else if (my > cy) {		//7
					v[i].x -= dx[7];
					v[i].y -= dy[7];
				}
			}
			else if (mx == cx) {		//2,5,8�� ��ġ�� ����
				if (my < cy) {		//2
					v[i].x -= dx[2];
					v[i].y -= dy[2];
				}
				else if (my > cy) {		//8
					v[i].x -= dx[8];
					v[i].y -= dy[8];
				}
			}
			else if (mx < cx) {		//3,6,9�� ��ġ�� ����
				if (my < cy) {		//3
					v[i].x -= dx[3];
					v[i].y -= dy[3];
				}
				else if (my == cy) {	//6
					v[i].x -= dx[6];
					v[i].y -= dy[6];
				}
				else if (my > cy) {		//9
					v[i].x -= dx[9];
					v[i].y -= dy[9];
				}
			}
			if (arr[v[i].y][v[i].x] == 'I') {		//�� �Ƶ��̳�� �ε����� ���
				finish = true;
				break;
			}
			else if (check[v[i].y][v[i].x] == -1) 		//�� ���, ���° �Ƶ��̳밡 �����ϴ��� ����
				check[v[i].y][v[i].x] = i;
			else if (check[v[i].y][v[i].x] != -1) {		//�� �ٸ� ��ģ �Ƶ��̳�� �ε����� ���
				v[i].crash = true;						//��� ������ �Ƶ��̳�
				v[check[v[i].y][v[i].x]].crash = true;	//�̹� �������� �Ƶ��̳�
			}
		}
	}
	//�ر��Ȱ͵� ó��
	for (int i = 0; i < v.size(); i++) {
		if (v[i].crash)		arr[v[i].y][v[i].x] = '.';
	}
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].crash)	arr[v[i].y][v[i].x] = 'R';
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				mx = j; my = i;
			}
			else if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				tmp.crash = false;
				v.push_back(tmp);
			}
		}
	string str;
	cin >> str;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		int dir = str[i] - '0';
		//1. �� �Ƶ��̳� �̵�
		arr[my][mx] = '.';
		mx += dx[dir]; my += dy[dir];
		//2. ��ģ �Ƶ��̳�� �ε������� Ȯ��
		if (arr[my][mx] == 'R') {		//�ε��� ���
			finish = true;
			result = i + 1;
			break;
		}
		arr[my][mx] = 'I';
		//3,4,5. ��ģ �Ƶ��̳� �̵�
		mv();
		if (finish) {
			result = i + 1;
			break;
		}
	}
	if (finish) cout << "kraj " << result;
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << arr[i][j];
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}