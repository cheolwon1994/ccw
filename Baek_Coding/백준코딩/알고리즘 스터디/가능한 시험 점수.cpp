#define MAX 10001
#include <iostream>
#include <vector>
using namespace std;
int num;
int arr[100];
bool sum[MAX];

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//ÃÊ±âÈ­
		for (int i = 0; i < MAX; i++)	sum[i] = false;
		sum[0] = true;
		vector<int> v;
		v.push_back(0);

		cin >> num;
		for (int i = 0; i < num; i++)
			cin >> arr[i];
		for (int i = 0; i < num; i++) {
			int len = v.size();
			for (int j = 0; j < len; j++) {
				if (sum[arr[i] + v[j]] == false) {
					sum[arr[i] + v[j]] = true;
					v.push_back(arr[i] + v[j]);
				}
			}
		}
		cout << "#" << t << " " << v.size() << endl;
	}
	system("pause");
	return 0;
}