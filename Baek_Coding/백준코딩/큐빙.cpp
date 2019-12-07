#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

struct info {
	int x;
	int y;
	char a;
};

vector<info> v;
info tmp;
int test_case;
char dup[12][10];
char cube[12][10] = {
"xxxwwwxxx",
"xxxwwwxxx",
"xxxwwwxxx",
"gggrrrbbb",
"gggrrrbbb",
"gggrrrbbb",
"xxxyyyxxx",
"xxxyyyxxx",
"xxxyyyxxx",
"xxxoooxxx",
"xxxoooxxx",
"xxxoooxxx"
};

void insert(vector <info> v, int dir) {
	string str = "";
	if (dir == 1) {
		for (int i = 0; i < 3; i++)
			str += v[11 - i].a;
		for (int i = 8; i >= 0; i--) {
			v[i + 3].a = v[i].a;
		}
		for (int i = 0; i < 3; i++)
			v[2 - i].a = str[i];
	}
	else if (dir == -1) {
		for (int i = 0; i < 3; i++)
			str += v[i].a;
		for (int i = 0; i < 9; i++)
			v[i].a = v[i + 3].a;
		for (int i = 0; i < 3; i++)
			v[9 + i].a = str[i];
	}
	for (int i = 0; i < 12; i++) 
		dup[v[i].y][v[i].x] = v[i].a;
}

void rotate(char c, int dir) {
	v.clear();
	if (c == 'F') {
		for (int j = 0; j < 3; j++) {
			tmp.x = 3 + j;
			tmp.y = 2;
			tmp.a = dup[2][3 + j];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = 6;
			tmp.y = 3 + i;
			tmp.a = dup[3 + i][6];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = 5 - i;
			tmp.y = 6;
			tmp.a = dup[6][5 - i];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = 2;
			tmp.y = 5 - i;
			tmp.a = dup[5 - i][2];
			v.push_back(tmp);
		}		
	}
	else if (c == 'U') {
		for (int i = 0; i < 3; i++) {
			tmp.x = 3 + i;
			tmp.y = 11;
			tmp.a = dup[11][3 + i];
			v.push_back(tmp);
		}
		for (int i = 8; i >= 0; i--) {
			tmp.x = i;
			tmp.y = 3;
			tmp.a = dup[3][i];
			v.push_back(tmp);
		}
	}
	else if (c == 'D') {
		for (int i = 0; i < 6; i++) {
			tmp.x = 3 + i;
			tmp.y = 5;
			tmp.a = dup[5][3 + i];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = 5 - i;
			tmp.y = 9;
			tmp.a = dup[9][5 - i];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = i;
			tmp.y = 5;
			tmp.a = dup[5][i];
			v.push_back(tmp);
		}
	}
	else if (c == 'B') {
		for (int i = 0; i < 3; i++) {
			tmp.x = 5 - i;
			tmp.y = 0;
			tmp.a = dup[0][5 - i];
			v.push_back(tmp);
		}
		for (int i = 0; i < 3; i++) {
			tmp.x = 0;
			tmp.y = 3 + i;
			tmp.a = dup[3 + i][0];
			v.push_back(tmp);
		}for (int i = 0; i < 3; i++) {
			tmp.x = i + 3;
			tmp.y = 8;
			tmp.a = dup[8][i+3];
			v.push_back(tmp);
		}for (int i = 0; i < 3; i++) {
			tmp.x = 8;
			tmp.y = 5 - i;
			tmp.a = dup[5 - i][8];
			v.push_back(tmp);
		}
	}
	else if (c == 'L') {
		for (int i = 0; i < 12; i++) {
			tmp.x = 3;
			tmp.y = i;
			tmp.a = dup[i][3];
			v.push_back(tmp);
		}
	}
	else if (c == 'R') {
		for (int i = 0; i < 3; i++) {
			tmp.x = 5;
			tmp.y = 2 - i;
			tmp.a = dup[2 - i][5];
			v.push_back(tmp);
		}
		for (int i = 0; i < 9; i++) {
			tmp.x = 5;
			tmp.y = 11 - i;
			tmp.a = dup[11 - i][5];
			v.push_back(tmp);
		}
	}
	insert(v, dir);
}

void spin(int y, int x, int dir) {
	/*
	y-1,x-1   1   y-1,x+1
						2
	y+1,x-1	 3    y+1,x+1
	*/
	int test = 1;
	if (dir == 1)
		test = 3;

	while (test > 0) {		//반시계
		int tmp[3] = { dup[y + 1][x - 1],dup[y][x - 1],dup[y - 1][x - 1] };
		for (int i = 0; i < 3; i++)
			dup[y + 1 - i][x - 1] = dup[y - 1][x - 1 + i];
		for (int i = 0; i < 3; i++)
			dup[y - 1][x - 1 + i] = dup[y - 1 + i][x + 1];
		for (int i = 0; i < 3; i++)
			dup[y - 1 + i][x + 1] = dup[y + 1][x + 1 - i];
		for (int i = 0; i < 3; i++)
			dup[y + 1][x + 1 - i] = tmp[i];
		test--;
	}
}

int main() {
	cin >> test_case;
	int t;
	int dir;		//반시계 : -1, 시계 : 1
	char c;
	for (int i = 0; i < test_case; i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 9; k++)
				dup[j][k] = cube[j][k];
		}
		cin >> t;
		string str;
		for (int j = 0; j < t; j++) {
			cin >> str;
			c = str[0];
			if (str[1] == '-')
				dir = -1;
			else
				dir = 1;
			rotate(c, dir);
			if (c == 'L')
				spin(4, 1, dir);
			else if (c == 'U')
				spin(1, 4, dir);
			else if (c == 'D')
				spin(7, 4, dir);
			else if (c == 'F')
				spin(4, 4, dir);
			else if (c == 'B')
				spin(10, 4, dir);
			else if (c == 'R')
				spin(4, 7, dir);		
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 3; k < 6; k++) {
				cout << dup[j][k];
			}
			cout << endl;
		}
	}
	system("PAUSE");
	return 0;
}