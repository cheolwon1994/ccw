#include <iostream>
#include <vector>
using namespace std;
int num;
int arr[4] = { 1,5,10,50 };
vector<int> v;
void start(int cnt) {
	if (cnt == num) {
		cout << v.size();
		return;
	}

	if (cnt == 0) {
		for (int i = 0; i < 4; i++) 
			v.push_back(arr[i]);
		start(cnt + 1);
	}
	else {
		vector<int> temp;
		bool check[1001] = { false, };
		temp = v;
		v.clear();
		for (int i = 0; i < temp.size(); i++) {
			int val = temp[i];
			for (int j = 0; j < 4; j++) {
				if (!check[val + arr[j]]) {
					check[val + arr[j]] = true;
					v.push_back(val + arr[j]);
				}
			}
		}
		start(cnt + 1);
	}
}

int main() {
	cin >> num;
	start(0);
	system("pause");
	return 0;
}