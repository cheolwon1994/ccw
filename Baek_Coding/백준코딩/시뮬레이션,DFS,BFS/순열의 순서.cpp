#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int num, tmp;
long long order;
long long fact[20];
long long arr[21];
bool check[21];
void factorial(int a) {
	long long n=1;
	fact[0] = 1;
	for (int i = 1; i <= a; i++) {
		n *= i;
		fact[i] = n;
	}
}

int main() {
	cin >> num;
	factorial(num);
	cin >> tmp;
	memset(check, false, sizeof(check));
	if (tmp == 1) {
		cin >> order;
		int t;
		long long remain;
		vector<int> ans;
		remain = order - 1;
		for (int i = 0; i < num; i++) {
			if (i == num - 1) {
				t = 0;
			}
			else {
				t = remain / fact[num - 1 - i];
				remain = remain % fact[num - 1 - i];
			}
			for (int j = 1; j <= num; j++) {
				if (t == 0) {
					if (check[j] == true)
						continue;
					else {
						check[j] = true;
						ans.push_back(j);
						break;
					}
				}
				if (check[j] == false)
					t--;
			}
		}
		for (int i = 0; i < num; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	else {
		vector<int> v;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
			v.push_back(arr[i]);
		}
		sort(v.begin(), v.end());
		long long result = 1;
		int dup = num - 1;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (arr[i] == v[j]) {
					result += j*fact[dup--];
					v.erase(v.begin()+j);
					break;
				}
			}
		}	
		cout << result << endl;
	}
	system("pause");
	return 0;
}