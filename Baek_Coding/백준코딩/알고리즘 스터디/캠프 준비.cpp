#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long num, mini, maxi, gap, result = 0;
long long arr[15];
bool flag[15];
vector<long long> v;
void start(int cnt, int idx) {
	if (cnt == num) {
		/*for (int i = 0; i < num; i++)
			cout << v[i] << " ";
		cout << endl;*/
		if (arr[v[v.size() - 1]] - arr[v[0]] >= gap) {
			long long sum = 0;
			for (int i = 0; i < v.size(); i++)
				sum += arr[v[i]];
			if (sum >= mini && sum <= maxi)
				result++;
		}
		return;
	}
	if (cnt > 1) {
		/*for (int i = 0; i < cnt; i++)
			cout << v[i] << " ";
		cout << endl;*/
		if (arr[v[v.size() - 1]] - arr[v[0]] >= gap) {
			long long sum = 0;
			for (int i = 0; i < v.size(); i++)
				sum += arr[v[i]];
			if (sum >= mini && sum <= maxi)
				result++;
		}
	}
	for (int i = idx; i < num; i++) {
		if (!flag[i]) {
			flag[i] = true;
			v.push_back(i);
			start(cnt + 1, i + 1);
			v.pop_back();
			flag[i] = false;
		}
	}
}

int main() {
	cin >> num >> mini >> maxi >> gap;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	sort(arr, arr + num);
	start(0,0);
	cout << result;
	system("pause");
	return 0;
}