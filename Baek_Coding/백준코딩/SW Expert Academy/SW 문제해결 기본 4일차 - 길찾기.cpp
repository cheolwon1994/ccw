#include <iostream>
#include <string.h>
using namespace std;
int arr[100];
int arr2[100];
bool finish_avail;
void go(int cur) {
	if (cur == 99) {
		finish_avail = true;
		return;
	}
	int tmp;
	if (arr[cur] != 0) {
		tmp = arr[cur];
		arr[cur] = 0;
		go(tmp);
		arr[cur] = tmp;
	}
	if (arr2[cur] != 0) {
		tmp = arr2[cur];
		arr2[cur] = 0;
		go(tmp);
		arr[cur] = tmp;
	}
}

int main() {
	int test, node, start, end;
	for (int t = 1; t <= 10; t++) {
		cin >> test >> node;
		finish_avail = false;
		memset(arr, 0, sizeof(arr));
		memset(arr2, 0, sizeof(arr2));
		for (int i = 0; i < node; i++) {
			cin >> start >> end;
			if (arr[start] == 0) 
				arr[start] = end;			
			else
				arr2[start] = end;
		}
		go(0);
		int result = finish_avail == true ? 1 : 0;
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}