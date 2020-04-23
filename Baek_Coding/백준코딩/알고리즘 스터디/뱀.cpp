#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct info {
	long long sx, sy, dir, len;
};
info tmp;
vector<info> v;
long long limit, order, val;
char c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> limit >> order;
	bool finish = false;
	long long result = 0;
	long long cx = 0, cy = 0, cd = 1, val, nx, ny;		//현재 위치, 방향
	for (int i = 0; i <= order; i++) {
		if (i != order)
			cin >> val >> c;
		else if (i == order)
			val = 987654321;
		if (finish) continue;		//이미 끝난 경우
		long long temp = 987654321;
		//바깥쪽으로 나가지는 경우
		nx = cx + dx[cd] * val;
		ny = cy + dy[cd] * val;
		if (nx < -limit) 		temp = min(temp, cx - (-limit) + 1);
		else if (nx > limit) 	temp = min(temp, limit - cx + 1);
		else if (ny < -limit) 	temp = min(temp, cy - (-limit) + 1);
		else if (ny > limit) 	temp = min(temp, limit - cy + 1);

		if (v.size() > 0) {		//마지막 길이와는 비교할 필요 없음
			for (int j = 0; j < v.size() - 1; j++) {
				long long sx = v[j].sx;
				long long sy = v[j].sy;
				long long len = v[j].len;
				long long dir = v[j].dir;
				long long ex = sx + dx[dir] * len;
				long long ey = sy + dy[dir] * len;
				//몸통과 부딪히는 경우
				if (cd == 0) {
					if (dir == 0 && cx == sx && cy <= sy && sy <= ny) 
						temp = min(temp, sy - cy);
					else if (dir == 1 && sx <= cx && cx <= ex && cy <= sy && sy <= ny) 
						temp = min(temp, sy - cy);
					else if (dir == 2 && cx == sx && cy <= ey && ey <= ny) 
						temp = min(temp, ey - cy);
					else if (dir == 3 && ex <= cx && cx <= sx && cy <= ey && ey <= ny) 
						temp = min(temp, ey - cy);
				}
				else if (cd == 1) {
					if (dir == 0 && cx <= sx && sx <= nx && sy <= cy && cy <= ey) 
						temp = min(temp, ex - cx);
					else if (dir == 1 && cy == sy && cx <= sx && sx <= nx) 
						temp = min(temp, sx - cx);		
					else if (dir == 2 && cx <= sx && sx <= nx && ey <= ny && ny <= sy)
						temp = min(temp, sx - cx);

					else if (dir == 3 && cy == sy && cx <= ex && ex <= nx)
						temp = min(temp, ex - cx);
				}
				else if (cd == 2) {
					if (dir == 0 && cx == sx && ny <= ey && ey <= cy)
						temp = min(temp, cy - ey);
					else if (dir == 1 && sx <= cx && cx <= ex && ny <= sy && sy <= cy)
						temp = min(temp, cy - ey);
					else if (dir == 2 && cx == sx && ny <= sy && sy <= cy)
						temp = min(temp, cy - sy);
					else if (dir == 3 && ny <= sy && sy <= cy && ex <= cx && cx <= sx)
						temp = min(temp, cy - sy);
				}
				else if (cd == 3) {
					if (dir == 0 && sy <= cy && cy <= ey && nx <= ex && ex <= cx)
						temp = min(temp, cx - sx);
					else if (dir == 1 && sy == cy && nx <= ex && ex <= cx)
						temp = min(temp, cx - ex);
					else if (dir == 2 && nx <= sx && sx <= cx && ey <= cy && cy <= sy)
						temp = min(temp, cx - ex);
					else if (dir == 3 && sy == cy && nx <= sx && sx <= cx)
						temp = min(temp, cx - sx);
				}
			}
		}
		if (temp != 987654321) {
			finish = true;
			result += temp;
		}
		else {
			tmp.dir = cd;
			tmp.sx = cx;
			tmp.sy = cy;
			tmp.len = val;
			v.push_back(tmp);
			cx = nx;
			cy = ny;
			//방향 전환
			if (c == 'L') cd = (cd + 3) % 4;
			else cd = (cd + 1) % 4;
			result += val;			
		}
	}
	cout << result;
	system("pause");
	return 0;
}