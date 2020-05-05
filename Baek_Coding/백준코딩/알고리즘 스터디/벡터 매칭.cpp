#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
int x[20], y[20];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, num;
	long long result;
	double ans;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		result = 9223372036854775807;
		for (int i = 0; i < num; i++) {
			cin >> x[i] >> y[i];
		}
		vector<int> v;
		for (int i = 0; i < num / 2; i++)
			v.push_back(0);
		for (int i = 0; i < num / 2; i++)
			v.push_back(1);
		do {
			long long tx = 0, ty = 0;
			long long t_result;
			for (int i = 0; i < num; i++) {
				if (v[i] == 0) {
					tx += x[i];
					ty += y[i];
				}
				else {
					tx -= x[i];
					ty -= y[i];
				}
			}
			t_result = tx * tx + ty * ty;			
			result = min(result, t_result);
	
		} while (next_permutation(v.begin(), v.end()));
		ans = sqrt(result);
		printf("%.12lf\n", ans);
	}
	system("pause");
	return 0;
}