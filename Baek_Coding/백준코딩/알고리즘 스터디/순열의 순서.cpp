#include <iostream>
#include <vector>
using namespace std;
long long fact[21];

long long num, k, order;
int main() {
	fact[0] = 1;
	for (int i = 1; i < 21; i++)
		fact[i] = fact[i - 1] * i;
	cin >> num >> k;
	//초기화
	bool check[21] = { false, };
	for (int i = 1; i <= num; i++)
		check[i] = true;
	//cout << fact[20] << endl;
	if (k == 1) {		//해당 순열 출력
		cin >> order;
		long long tt;
		vector<int> ans;
		order -= 1;
		for (int j = num - 1; j > 0; j--) {
			tt = (int)(order / fact[j]);
			for (int k = 1; k <= num; k++) {
				if (check[k]) {
					if (tt == 0) {
						check[k] = false;
						ans.push_back(k);
						break;
					}
					else
						tt--;
				}
			}
			order -= (int)(order / fact[j])*fact[j];
		}
		for (int i = 1; i <= num; i++)
			if (check[i]) {
				ans.push_back(i);
				break;
			}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}
	else if (k == 2) {
		vector<int> v;
		int tt;
		long long result = 1;
		for (int i = 0; i < num; i++) {
			cin >> tt;
			v.push_back(tt);
		}
		int cnt;
		for (int k = 0; k < num; k++) {
			int val = v[k];
			cnt = 0;
			for (int i = 1; i <=num; i++) {
				if (check[i] == false)
					continue;
				else {
					if (val == i) {
						check[i] = false;
						result += cnt * fact[num - (k + 1)];
						break;
					}
					else
						cnt++;
				}
			}
		}
		cout << result;
	}
	system("pause");
	return 0;
}