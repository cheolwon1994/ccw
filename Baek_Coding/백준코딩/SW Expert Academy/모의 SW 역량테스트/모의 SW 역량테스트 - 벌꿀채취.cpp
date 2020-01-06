#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int result[10][10];
int arr[10][10];
bool dup[5];
int num, box, tot, ans, maxi;
vector<int> t;
vector<int> a;

bool desc(int a, int b) {
	return a > b;
}

void choice() {
	bool check[10][10] = { false, };
	int max, x, y;
	int cnt = 2;
	while (cnt > 0) {
		max = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num - box + 1; j++) {
				if (result[i][j] > max) {
					bool avail = true;
					for (int k = 0; k < box; k++) {
						if (check[i][j + k]) {
							avail = false;
							break;
						}
					}
					if (avail) {
						max = result[i][j];
						y = i;
						x = j;
					}
				}
			}
		}
		for (int k = 0; k < box; k++)
			check[y][x + k] = true;
		ans += max;
		cnt--;
	}
}

void find(int cnt, int mul) {
	maxi = max(maxi, mul);
	for (int i = 0; i < t.size(); i++) {
		if (cnt + t[i] > tot || dup[i])
			continue;
		else {
			a.push_back(t[i]);
			dup[i] = true;
			find(cnt + t[i], mul + (t[i] * t[i]));
			a.pop_back();
			dup[i] = false;
		}
	}
}

void start() {
	int honey, cal;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - box + 1; j++) {
			int sum = 0;
			t.clear();
			for (int k = 0; k < box; k++) {
				honey = arr[i][j + k];
				t.push_back(honey);
				sum += honey;
			}
			if (sum <= tot) {
				cal = 0;
				for (int k = 0; k < box; k++)
					cal += t[k] * t[k];
				result[i][j] = cal;
			}
			else {
				a.clear();
				maxi = 0;
				memset(dup, false, sizeof(dup));
				find(0, 0);
				result[i][j] = maxi;
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		ans = 0;
		cin >> num >> box >> tot;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];
		start();
		choice();
		cout << "#" << t << " " << ans << endl;
	}
	system("pause");
	return 0;
}