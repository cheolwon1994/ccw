#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int num;
long long result;
int arr[16][16];
vector<int> v;		//A���Ŀ� ���� ���

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//�ʱ�ȭ
		result = MAX;
		v.clear();

		cin >> num;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) 
				cin >> arr[i][j];			
		for (int i = 0; i < num / 2; i++)
			v.push_back(0);
		for (int i = 0; i < num / 2; i++)
			v.push_back(1);

		do {
			long long a_ingredient = 0;
			long long b_ingredient = 0;
			vector<int> a;		//A���Ŀ� ���� ����ȣ ����
			vector<int> b;
			for (int i = 0; i < num; i++) {
				if (v[i] == 1)
					a.push_back(i);
				else
					b.push_back(i);
			}
			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j <a.size(); j++) {
					if (i == j)
						continue;
					a_ingredient += arr[a[i]][a[j]];
				}
			}
			for (int i = 0; i < b.size(); i++) {
				for (int j = 0; j < b.size(); j++) {
					if (i == j)
						continue;
					b_ingredient += arr[b[i]][b[j]];
				}
			}
			result = min(result, abs(b_ingredient - a_ingredient));
		} while (next_permutation(v.begin(), v.end()));
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}