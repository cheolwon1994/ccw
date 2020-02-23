#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int result = 0;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				//printf("%d번째에서 찾았습니다.\n", i - patternSize + 2);
				result++;
				j = table[j];
			}
			else
				j++;
		}
	}
}

int main() {
	string parent, pattern = "I";
	int num, parent_size;
	cin >> num >> parent_size >> parent;
	for (int i = 0; i < num; i++)
		pattern += "OI";
	KMP(parent, pattern);
	cout << result;
	system("pause");
	return 0;
}