#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int a_dir[100];
int b_dir[100];
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };
struct info {
	int x, y, dist, power;
};
info tmp;
vector<info> bc;
vector<int> a_avail;
vector<int> b_avail;
int limit, num, result;

void start() {
	int ax = 1;
	int ay = 1;
	int bx = 10;
	int by = 10;
	for (int t = 0; t <= limit; t++) {
		a_avail.clear();
		b_avail.clear();
		for (int i = 0; i < num; i++) {		//연결 가능한 bc 모두 추가
			if (abs(ax - bc[i].x) + abs(ay - bc[i].y) <= bc[i].dist)
				a_avail.push_back(i);
			if (abs(bx - bc[i].x) + abs(by - bc[i].y) <= bc[i].dist)
				b_avail.push_back(i);
		}
		//계산

		int t_result = 0;
		if (a_avail.empty() && !b_avail.empty()) {	
			for (int i = 0; i < b_avail.size(); i++)
				t_result = max(t_result, bc[b_avail[i]].power);			
		}
		else if (!a_avail.empty() && b_avail.empty()) {
			for (int i = 0; i < a_avail.size(); i++)
				t_result = max(t_result, bc[a_avail[i]].power);
		}
		else if (!a_avail.empty() && !b_avail.empty()) {
			for (int i = 0; i < a_avail.size(); i++) {
				for (int j = 0; j < b_avail.size(); j++) {
					int temp = 0;
					if (a_avail[i] == b_avail[j]) temp = bc[a_avail[i]].power;
					else 
						temp = bc[b_avail[j]].power + bc[a_avail[i]].power;				
					t_result = max(t_result, temp);
				}
			}
		}
		result += t_result;
		//이동
		ax += dx[a_dir[t]];
		ay += dy[a_dir[t]];
		bx += dx[b_dir[t]];
		by += dy[b_dir[t]];
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> limit >> num;
		result = 0;
		bc.clear();
		for (int i = 0; i < limit; i++)
			cin >> a_dir[i];
		for (int i = 0; i < limit; i++)
			cin >> b_dir[i];
		for (int i = 0; i < num; i++) {
			int x, y, dist, power;
			cin >> x >> y >> dist >> power;
			tmp.x = x; tmp.y = y; tmp.dist = dist; tmp.power = power;
			bc.push_back(tmp);
		}
		start();
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}