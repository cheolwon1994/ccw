#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[20][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, result = 987654321;
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	for (int t = 1; t < num - 1; t++) {
		vector<int> v;
		for (int i = 0; i < t; i++)
			v.push_back(0);
		for (int i = 0; i < num - t; i++)
			v.push_back(1);

		do {
			int a_sum = 0, b_sum = 0;
			vector<int> a, b;
			for (int i = 0; i < num; i++) {
				if (v[i] == 0) a.push_back(i);
				else b.push_back(i);
			}
			for (int i = 0; i < a.size()-1; i++) 
				for (int j = i + 1; j < a.size(); j++) 
					a_sum += (arr[a[i]][a[j]] + arr[a[j]][a[i]]);					
			for (int i = 0; i < b.size() - 1; i++) 
				for (int j = i + 1; j < b.size(); j++) 
					b_sum += (arr[b[i]][b[j]] + arr[b[j]][b[i]]);

			result = min(result, abs(a_sum - b_sum));
		} while (next_permutation(v.begin(), v.end()));
	}
	cout << result;
	system("pause");
	return 0;
}