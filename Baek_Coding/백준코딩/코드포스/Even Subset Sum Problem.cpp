#include <iostream>
#include <algorithm>
using namespace std;
int arr[100];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
			cin >> arr[i];
		bool even = false;
		bool avail = false;
		int even_result, odd1 = 0, odd2;
		for (int i = 0; i < num; i++) {
			if (arr[i] % 2 == 0) {
				even = true;
				even_result = i + 1;
				break;
			}
			else {
				if (odd1 == 0) odd1 = i + 1;
				else {
					odd2 = i + 1;
					avail = true;
					break;
				}
			}
		}
		if (even) 
			cout << 1 << '\n' << even_result << '\n';
		else {
			if (avail)
				cout << 2 << '\n' << odd1 << " " << odd2 << '\n';
			else
				cout << -1 << '\n';
		}				
	}
	return 0;
}