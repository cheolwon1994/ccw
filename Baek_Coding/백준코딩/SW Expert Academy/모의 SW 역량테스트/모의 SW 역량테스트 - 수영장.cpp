#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int month[13];
int charge[4];		//1일,1개월,3개월,1년
vector<int> v;
long long result;

void cal() {
	long long temp = 0;
	int idx = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]== 1) {
			if (charge[0] * month[idx] > charge[1])
				temp += charge[1];
			else
				temp += charge[0] * month[idx];
			idx++;
		}
		else if(v[i]==3){
			temp += charge[2];
			idx += 3;
		}
	}
	result = min(result, temp);
}

void start(int m) {
	if (m == 12) {
		cal();
		return;
	}
	if (m + 1 <= 12) {
		v.push_back(1);
		start(m + 1);
		v.pop_back();
	}
	if (m + 3 <= 12) {
		v.push_back(3);
		start(m + 3);
		v.pop_back();
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		v.clear();
		result = 0;
		for (int i = 0; i < 4; i++)
			cin >> charge[i];
		for (int i = 1; i < 13; i++) {
			cin >> month[i];
			result += month[i] * charge[0];		//전부 1일치 계산
		}
		if (charge[3] < result)
			result = charge[3];
		start(0);
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}