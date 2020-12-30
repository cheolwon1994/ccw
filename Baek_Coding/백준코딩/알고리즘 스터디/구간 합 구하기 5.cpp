#include <iostream>
using namespace std;

long long arr[1025][1025];
int num, query, a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> query;
	for(int i=1;i<=num;i++)
		for (int j = 1; j <= num; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
	for (int i = 0; i < query; i++) {
		cin >> a >> b >> c >> d;
		long long result = 0;
		for (int j = a; j <= c; j++)
			result += (arr[j][d] - arr[j][b-1]);
		cout << result << '\n';
	}
	return 0;
}