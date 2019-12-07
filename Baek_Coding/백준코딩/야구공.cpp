#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
int num;

int arr[50][9];
int order_arr[10];		//타순, 0번 없이 order_arr[1] : 1번 타자
int check[10];
int result = 0;
int state[4];		//주자 상태 1,2,3루 state[0]은 사용 안함
/***************************************
1. 타선의 순서를 정한다.
2. 각 타선에 ㄸ
****************************************/

void hit() {
	int tem = 0;			//이닝 카운트 0이닝부터 시작이라고 가정
	int hit_num = 1;		//공을 치는 타자
	int tot_score = 0;
	while (tem < num) {		//총 경기
		int out = 0;
		while (out < 3) {		//이닝 마다
			if (arr[tem][order_arr[hit_num]-1] == 0) 
				out++;
			else if (arr[tem][order_arr[hit_num]-1] == 1) {
				for (int i = 3; i > 1; i--) {
					if (i == 3 && state[i] == 1) {
						state[i] = 0;
						tot_score++;
					}
					if (i != 1)
						state[i] = state[i - 1];
				}
				state[1] = 1;
			}
			else if (arr[tem][order_arr[hit_num]-1] == 2) {
				for (int i = 3; i > 0; i--) {
					if (i == 2 || i == 3) {
						if (state[i] == 1) {
							state[i] = 0;
							tot_score++;
						}
					}
					else if (i == 1) {
						if (state[i] == 1) {
							state[i + 2] = 1;
							state[i] = 0;
						}
						state[2] = 1;
					}
				}
			}
			//3루타
			else if (arr[tem][order_arr[hit_num]-1] == 3) {
				for (int i = 3; i > 0; i--) {
					if (state[i] == 1) {
						state[i] = 0;
						tot_score++;
					}
				}
				state[3] = 1;
			}
			//홈런
			else {
				for (int i = 3; i > 0; i--) {
					if (state[i] == 1) {
						state[i] = 0;
						tot_score++;
					}
				}
				tot_score++;
			}
			hit_num +=1;
			if (hit_num == 10)
				hit_num = 1;
		}
		for (int i = 1; i < 4; i++)
			state[i] = 0;
		tem++;
	}
	/*if (result < tot_score) {
		result = tot_score;
		for (int i = 1; i < 10; i++)
			cout << order_arr[i];
		cout << "  "<< result << "\n";
	}*/
	result = max(result, tot_score);
}

void order(int a) {		//a는 타선과 관련, i는 선수번호와 관련
	if (a == 10) {
		//점수 측정
		hit();
		return;
	}
	//선수 번호
	for (int i = 2; i < 10; i++) {
		if (check[i] != 1) {
			check[i] = 1;
			if (a == 4) {
				order_arr[a + 1] = i;
				order(a + 2);
				order_arr[a + 1] = 0;
			}
			else {
				order_arr[a] = i;
				order(a + 1);
				order_arr[a] = 0;
			}
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> num;

	for (int i = 0; i < num; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	//초기화 작업
	memset(check, 0, sizeof(check));
	order_arr[4] = 1;		//선수 1번을 4번 타자로 넣는다.
	check[1] = 1;			//선수 1번 사용했다고 표시

	order(1);		//순서 정하기
	cout << result;

	system("PAUSE");
	return 0;
}