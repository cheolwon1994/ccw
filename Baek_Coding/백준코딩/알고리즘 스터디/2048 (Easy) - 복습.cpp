#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int num, result = 0;
int arr[20][20];
vector<int> order;

void dfs2(int cnt) {
	if (cnt == 5) {
		int dup[20][20];
		memcpy(dup, arr, sizeof(dup));
		for (int l = 0; l < cnt; l++) {
			int m = order[l];
			if (m == 0) {		//위로
				for (int j = 0; j < num; j++) {
					vector<int> v1, v2;
					for (int i = 0; i < num; i++)
						if (dup[i][j] != 0)
							v1.push_back(dup[i][j]);
					if (!v1.empty()) {
						for (int i = 0; i < v1.size(); i++) {
							if (i + 1 < v1.size() && v1[i] == v1[i + 1]) {
								v2.push_back(v1[i] * 2);
								i++;
							}
							else
								v2.push_back(v1[i]);
						}
					}
					for (int i = 0; i < v2.size(); i++)
						dup[i][j] = v2[i];
					for (int i = v2.size(); i < num; i++)
						dup[i][j] = 0;
				}
			}
			else if (m == 1) {		//오른쪽으로
				for (int i = 0; i < num; i++) {
					vector<int> v1, v2;
					for (int j = num-1; j >=0; j--)
						if (dup[i][j] != 0)
							v1.push_back(dup[i][j]);
					if (!v1.empty()) {
						for (int j = 0; j < v1.size(); j++) {
							if (j + 1 < v1.size() && v1[j] == v1[j + 1]) {
								v2.push_back(v1[j] * 2);
								j++;
							}
							else
								v2.push_back(v1[j]);
						}
					}
					for (int j = 0; j < v2.size(); j++)
						dup[i][num - 1 - j] = v2[j];
					for (int j = 0; j <num-v2.size(); j++)
						dup[i][j] = 0;
				}
			}
			else if (m == 2) {		//밑으로
				for (int j = 0; j < num; j++) {
					vector<int> v1, v2;
					for (int i = num-1; i >=0; i--)
						if (dup[i][j] != 0)
							v1.push_back(dup[i][j]);
					if (!v1.empty()) {
						for (int i = 0; i < v1.size(); i++) {
							if (i + 1 < v1.size() && v1[i] == v1[i + 1]) {
								v2.push_back(v1[i] * 2);
								i++;
							}
							else
								v2.push_back(v1[i]);
						}
					}
					for (int i = 0; i < v2.size(); i++)
						dup[num - 1 - i][j] = v2[i];
					for (int i = 0; i < num-v2.size(); i++)
						dup[i][j] = 0;
				}
			}
			else if (m == 3) {		//왼쪽으로
				for (int i = 0; i < num; i++) {
					vector<int> v1, v2;
					for (int j = 0; j < num; j++)
						if (dup[i][j] != 0) 
							v1.push_back(dup[i][j]);
					if (!v1.empty()) {
						for (int j = 0; j < v1.size(); j++) {
							if (j + 1 < v1.size() && v1[j] == v1[j + 1]) {
								v2.push_back(v1[j] * 2);
								j++;
							}
							else
								v2.push_back(v1[j]);
						}
					}
					for (int j = 0; j < v2.size(); j++)
						dup[i][j] = v2[j];
					for (int j = v2.size(); j < num; j++)
						dup[i][j] = 0;
				}
			}
		}
		int tt = 0;
		for (int i = 0; i < num; i++) 
			for (int j = 0; j < num; j++) 
				tt = max(tt, dup[i][j]);
		result = max(result, tt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		order.push_back(i);
		dfs2(cnt + 1);
		order.pop_back();
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	dfs2(0);
	cout << result;
	system("pause");
	return 0;
}