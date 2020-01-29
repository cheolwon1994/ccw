#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct info {
	int x, y;
};
info tmp;
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,-1,-1,1,1 };
int arr[8][8];
vector<info> king, rock;
vector<int> v;		//¸í·É
int num, n, order;

int main() {
	string str;
	cin >> str;
	n = str[0] - '0' - 17;
	num = 8 - (str[1] - '0');
	tmp.x = n;
	tmp.y = num;
	king.push_back(tmp);
	
	cin >> str;
	n = str[0] - '0' - 17;
	num = 8 - (str[1] - '0');
	tmp.x = n;
	tmp.y = num;
	rock.push_back(tmp);
	cin >> order;
	for (int i = 0; i < order; i++) {
		cin >> str;
		if (str == "R") v.push_back(0);
		else if (str == "L") v.push_back(1);
		else if (str == "B") v.push_back(2);
		else if (str == "T") v.push_back(3);
		else if (str == "RT") v.push_back(4);
		else if (str == "LT") v.push_back(5);
		else if (str == "RB") v.push_back(6);
		else if (str == "LB") v.push_back(7);
	}
	for (int i = 0; i < order; i++) {
		int cx, cy, nx, ny;
		cx = king[0].x;
		cy = king[0].y;
		nx = cx + dx[v[i]];
		ny = cy + dy[v[i]];
		if (nx >= 0 && ny >= 0 & nx < 8 && ny < 8) {
			if (nx == rock[0].x && ny == rock[0].y) {
				int tx, ty;
				tx = rock[0].x + dx[v[i]];
				ty = rock[0].y + dy[v[i]];
				if (tx >= 0 && ty >= 0 && tx < 8 && ty < 8) {
					rock[0].x = tx;
					rock[0].y = ty;
					king[0].y = ny;
					king[0].x = nx;
				}				
				continue;
			}
			else {
				king[0].y = ny;
				king[0].x = nx;
			}
		}
	}
	char c = king[0].x + 17 + '0';
	cout << c << 8- king[0].y<<endl;
	c = rock[0].x + 17 + '0';
	cout << c << 8 - rock[0].y;
	system("pause");
	return 0;
}