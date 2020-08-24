#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct info {
	int idx, height;
};
info tmp;
int arr[80001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int maxi = 0, num;
	long long result = 0;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	stack<info> s;
	tmp.height = maxi + 1;
	tmp.idx = num + 1;
	s.push(tmp);
	for (int i = num; i > 0; i--) {
		int ch = arr[i];
		while (!s.empty()) {
			int sh = s.top().height;
			int si = s.top().idx;
			if (sh < ch)		//오른쪽에 더 높은 빌딩이 없는 경우
				s.pop();
			else {		//오른쪽에 더 높은 빌딩이 있는 경우
				result += (si - i - 1);
				tmp.height = ch;
				tmp.idx = i;
				s.push(tmp);
				break;
			}
		}
	}
	cout << result;
	return 0;
}