#include <iostream>
#include <string>
using namespace std;
bool avail;
char arr[3][3];
int x,o,remain;		//.의 개수
int check(char c) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {		//가로 3개 확인
			if (arr[i][0] == c) 	cnt++;	
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {		//세로 3개 확인
			if (arr[0][i] == c) 	cnt++;
		}
	}
	//대각선 2개 확인
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
		if (arr[1][1] == c)		cnt++;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
		if (arr[1][1] == c) 	cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	while (1) {
		cin >> str;
		if (str == "end") break;
		avail = true;
		remain = 0;	x = 0;	o = 0;
		int cnt = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				arr[i][j] = str[cnt++];
				if (arr[i][j] == '.') remain++;
				else if (arr[i][j] == 'X') x++;
				else if (arr[i][j] == 'O') o++;
			}
		//0,X,.개수 확인
		if (remain == 0) {			//맨 마지막수까지 둔 경우, 'O'3개가 연속되면 안된다
			if (x - 1 != o)		avail = false;		//개수 비교
			int result = check('O');
			if (result > 0) avail = false;			
		}
		else if (remain % 2 == 0 && remain!=0) {		//X가 O보다 1개 더 많아야 하며 X가 이겨야 한다
			if (x - 1 != o)		avail = false;		//개수 비교
			int result = check('O');
			if (result > 0) avail = false;
			result = check('X');
			if (result == 0) avail = false;
		}
		else {			//X와 O의 개수가 같아야 하며 O가 이겨야 한다
			if (x != o)		avail = false;			//개수 비교
			int result = check('X');
			if (result > 0) avail = false;
			result = check('O');
			if (result == 0) avail = false;
		}
		if (avail) cout << "valid\n";
		else cout << "invalid\n";
	}
	system("pause");
	return 0;
}