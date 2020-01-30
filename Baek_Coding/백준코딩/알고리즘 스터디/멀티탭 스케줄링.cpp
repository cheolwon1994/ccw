#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
bool cur_use[101];
int arr[101];

int main() {
	int hole, num, thing, result = 0;
	cin >> hole >> num;
	for (int i = 0; i < num; i++) 
		cin >> arr[i];
	for (int i = 0; i < num; i++) {
		thing = arr[i];
		if (cur_use[thing]) continue;
		if (v.size() < hole) {	v.push_back(thing); cur_use[thing] = true;	}
		else {
			bool many[101] = { false, };
			int cnt = 0;
			for (int j = i; j < num; j++) {
				if (cur_use[arr[j]]) { //현재 사용중인것이 들어올 경우
					if (!many[arr[j]]) {
						cnt++;
						many[arr[j]] = true;
					}
				}			
				if (cnt == hole - 1) 	break;				
			}
			int idx = 0;
			for (int j = 1; j < hole; j++) {
				if (!many[v[j]]) {
					idx = j;
					break;
				}
			}
			cur_use[v[idx]] = false;
			v[idx] = thing;
			cur_use[thing] = true;
			result++;
		}
	}
	cout << result;
	system("pause");
	return 0;
}