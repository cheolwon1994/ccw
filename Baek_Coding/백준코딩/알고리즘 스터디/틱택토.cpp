#include <iostream>
#include <string>
using namespace std;
bool avail;
char arr[3][3];
int x,o,remain;		//.�� ����
int check(char c) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {		//���� 3�� Ȯ��
			if (arr[i][0] == c) 	cnt++;	
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {		//���� 3�� Ȯ��
			if (arr[0][i] == c) 	cnt++;
		}
	}
	//�밢�� 2�� Ȯ��
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
		//0,X,.���� Ȯ��
		if (remain == 0) {			//�� ������������ �� ���, 'O'3���� ���ӵǸ� �ȵȴ�
			if (x - 1 != o)		avail = false;		//���� ��
			int result = check('O');
			if (result > 0) avail = false;			
		}
		else if (remain % 2 == 0 && remain!=0) {		//X�� O���� 1�� �� ���ƾ� �ϸ� X�� �̰ܾ� �Ѵ�
			if (x - 1 != o)		avail = false;		//���� ��
			int result = check('O');
			if (result > 0) avail = false;
			result = check('X');
			if (result == 0) avail = false;
		}
		else {			//X�� O�� ������ ���ƾ� �ϸ� O�� �̰ܾ� �Ѵ�
			if (x != o)		avail = false;			//���� ��
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