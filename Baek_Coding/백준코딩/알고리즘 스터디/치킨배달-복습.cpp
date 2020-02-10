#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[50][50];
struct info {
	int x, y;
};
info tmp;
vector<info> c;			//전체 치킨집 정보
vector<info> house;		//집에 대한 정보
vector<info> ans;		//운영중인 치킨집에 대한 정보
int result = MAX;

void start() {
	int cx, cy, nx, ny;
	int t_result = 0;
	for (int i = 0; i < house.size(); i++) {
		cx = house[i].x;
		cy = house[i].y;
		int dist = abs(cx-ans[0].x)+abs(cy-ans[0].y);
		for (int j = 1; j < ans.size(); j++) {
			nx = ans[j].x;
			ny = ans[j].y;
			int t_Dist = abs(nx - cx) + abs(ny - cy);
			dist = min(dist, t_Dist);
		}
		t_result += dist;
	}
	result = min(result, t_result);
}

int main() {
	int num, chicken;
	cin >> num >> chicken;
	for(int i=0;i<num;i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tmp.x = j;
				tmp.y = i;
				house.push_back(tmp);
			}
			else if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				c.push_back(tmp);
			}
		}

	vector<int> v;
	for (int i = 0; i < c.size() - chicken; i++)
		v.push_back(0);
	for (int i = 0; i < chicken; i++)
		v.push_back(1);
	do {
		ans.clear();
		for(int i=0;i<v.size();i++)
			if (v[i] == 1) {
				tmp.x = c[i].x;
				tmp.y = c[i].y;
				ans.push_back(tmp);
			}
		start();
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
	system("pause");
	return 0;
}