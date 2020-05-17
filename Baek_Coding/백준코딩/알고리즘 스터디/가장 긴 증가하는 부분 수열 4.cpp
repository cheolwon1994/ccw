#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int pre_idx, len;
};
int arr[1000], num, idx = 0, max_len = 1;
info result[1001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		result[i].len = 1;
		result[i].pre_idx = i;
	}
	
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (result[i].len == result[j].len + 1 && arr[result[i].pre_idx]>arr[j]) {
					result[i].pre_idx = j;
				}
				else if (result[i].len < result[j].len + 1) {
					result[i].len = result[j].len + 1;
					result[i].pre_idx = j;
				}
			}
		}
	}
	for (int i = 1; i < num; i++) {
		if (result[i].len > max_len) {
			max_len = result[i].len;
			idx = i;
		}
	}
	while (1) {
		v.push_back(arr[idx]);
		if (idx == result[idx].pre_idx)
			break;
		idx = result[idx].pre_idx;
	}
	cout << v.size() << '\n';
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	system("pause");
	return 0;
}