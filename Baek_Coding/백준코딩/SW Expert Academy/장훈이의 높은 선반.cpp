#define MAX 200001
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[20];
int num, height;
int result;

int main() {
	int test,tot;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> height;
		tot = 0;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
			tot += arr[i];
		}
		result = MAX;
		int mid = num / 2;
		result = min(result, tot - height);
		for (int i = 1; i <= mid; i++) {
			vector<int> v;
			for (int j = 0; j < num - i; j++)
				v.push_back(0);
			for (int j = num - i; j < num; j++)
				v.push_back(1);
			do {
				int zero_sum = 0;
				int one_sum = 0;
				for (int j = 0; j < num; j++) {
					if (v[j] == 0)
						zero_sum += arr[j];
					else
						one_sum += arr[j];
				}
				if (zero_sum >= height) 
					result = min(result, zero_sum - height); 			
				if (one_sum >= height) 
					result = min(result, one_sum - height);					
			} while (next_permutation(v.begin(), v.end()));
		}		
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}