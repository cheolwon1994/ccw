#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
char arr[1000000];
int main() {
	int cnt = 0;
	char c;
	int break_point;
	while(1){
		scanf("%c", &c);
		break_point = c;
		if (break_point == 10)
			break;
		else
			arr[cnt++] = c;
	}
	cnt = 0;
	char *tok1 = strtok(arr, " ");
	while (tok1 != NULL) {
		//cout << tok1 << endl;
		cnt++;
		tok1 = strtok(NULL," ");
	}
	cout << cnt;

	system("pause");
	return 0;
}