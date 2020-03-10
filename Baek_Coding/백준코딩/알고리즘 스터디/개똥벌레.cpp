#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int from_down[500001];
int from_up[500001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, height, val;
	cin >> num >> height;
	for (int i = 0; i < num; i++) {
		cin >> val;
		if (i % 2 == 0) from_down[val]++;
		else from_up[val]++;		
	}
	for (int i = height-1; i >= 1; i--) {
		from_down[i] += from_down[i + 1];		//아래에서 부터 높이 i일때 부수는 장애물의 수
		from_up[i] += from_up[i + 1];			//위에서 부터 높이 i일때 부수는 장애물의 수
	}
	//밑에서부터 높이 i일때 부수는 장애물 수
	for (int i = 1; i <= height; i++)
		v.push_back(from_down[i] + from_up[height - i + 1]);
	sort(v.begin(),v.end());
	int dup = 1;
	int result = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == result) dup++;	
		else break;
	}
	cout << result << " " << dup;
	system("pause");
	return 0;
}