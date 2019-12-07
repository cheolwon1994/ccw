#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int sect_num;
int sect_pop[11];		//1~sect_num���� �޴´�
int arr[11][11];
int result = 987654321;

/**********************************
1. �ѷ� ������ ���
1.1 �� ���ű����� ��� 1���� ������ �־�� �Ѵ�
1.2 ���� ���ű��� ���� �����ؾ��Ѵ�.
2. ���� ��, �� ���ű��� �α��� ���ϰ� ���� ���Ѵ�
3. ���� ���� ���̰� ������ ���Ѱ����� ���� ��� ��ü
***********************************/

int cal(vector <int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += sect_pop[v[i]];
	return sum;
}

int check_next(vector<int> v) {
	int check[11];
	int semi_v[11];
	memset(semi_v, 0, sizeof(semi_v));
	for (int i = 0; i < v.size(); i++)
		semi_v[v[i]] = 1;
	memset(check, 0, sizeof(check));
	queue <int> q;
	q.push(v[0]);
	check[v[0]] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= sect_num; i++) {
			if (arr[cur][i] == 1 && check[i] != 1 && semi_v[i] == 1) {
				q.push(i);
				check[i] = 1;
				cnt++;
			}
		}
	}
	if (v.size() == cnt) return 1;
	else return 0;
}

void garry(vector<int> v) {
	vector<int> sect_a;
	vector<int> sect_b;
	sect_a.clear();
	sect_b.clear();

	for (int i = 0; i < sect_num; i++) {
		if (v[i] == 1)
			sect_a.push_back(i + 1);
		else if (v[i] == 0)
			sect_b.push_back(i + 1);
	}
	/*for (int i = 0; i < sect_a.size(); i++)
		cout << sect_a[i];
	cout << "\n";*/
	if (sect_a.empty() || sect_b.empty())
		return;

	int a = 0;
	//�����ߴ��� Ȯ��
	a += check_next(sect_a);
	a += check_next(sect_b);

	if (a < 2)			//���� ���Ѱ��
		return;
	else if (a == 2) {		//������ ���
		int pre_result = 0;
		pre_result = abs(cal(sect_a) - cal(sect_b));
		/*if (pre_result < result) {
			result = pre_result;
			cout << result << ": \n";
			for (int i = 0; i < sect_a.size(); i++)
				cout << sect_a[i];
			cout << endl;
		}*/
		result = min(result, pre_result);
	}
}

void mix(int a, vector<int> v ){
	if (a == sect_num) {
		garry(v);
		return;
	}
	v.push_back(0);
	mix(a + 1, v);
	v.pop_back();

	v.push_back(1);
	mix(a + 1, v);
	v.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(sect_pop, 0, sizeof(sect_pop));
	memset(arr, 0, sizeof(arr));
	cin >> sect_num;

	for (int i = 1; i <= sect_num; i++)
		cin >> sect_pop[i];
	int temp;
	for (int i = 1; i <= sect_num; i++) {
		cin >> temp;
		int tmp;
		for (int j = 0; j < temp; j++) {
			cin >> tmp;
			arr[i][tmp] = 1;
		}
	}
	vector<int> v;
	mix(0,v);
	if (result == 987654321)
		cout << -1;
	else
		cout << result;
	system("PAUSE");
	return 0;
}