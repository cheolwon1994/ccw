#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int color[4];	//RBYG

int main() {
	char c;
	int num, dup = 0, tri = 0,quad=0, all = 0, contin = 0, same_color = 0,maxi=0;
	for (int i = 0; i < 5; i++) {
		cin >> c >> num;
		if (c == 'R') color[0]++;
		else if (c == 'B') color[1]++;
		else if (c == 'Y') color[2]++;
		else if (c == 'G') color[3]++;
		maxi = max(maxi, num);
		arr[num]++;
	}
	int dup_idx1=0, dup_idx2;		//2개중복 중, 숫자 높은거 저장 -> 7번
	int tri_dup;
	int quad_dup;
	for (int i = 1; i < 10; i++) {
		if (i + 4 < 10 && arr[i]==1) {
			bool test = true;
			for (int j = i + 1; j < i+5; j++) {
				if (arr[j] != 1) {
					test = false;
					break;
				}
			}
			if (test) contin = 1;
		}
		if (arr[i] == 2) {
			dup++;
			if(dup_idx1==0)
				dup_idx1 = i;
			else if (dup_idx1 != 0)
				dup_idx2 = i;
		}
		if (arr[i] == 3) {
			tri++;
			tri_dup = i;
		}
		if (arr[i] == 4) {
			quad++;
			quad_dup = i;
		}
		if (arr[i] == 5)
			all++;
	}
	for (int i = 0; i < 4; i++)
		if (color[i] == 5)
			same_color = 1;
	int result = 0;
	if (same_color == 1 && contin == 1) result = 900 + maxi;		//1번
	else if (quad == 1) result = 800 + quad_dup;
	else if (tri == 1 && dup == 1) result = 700 + tri_dup * 10 + dup_idx1;
	else if (same_color) result = 600 + maxi;
	else if (contin) result = 500 + maxi;
	else if (tri == 1) result = 400 + tri_dup;
	else if (dup == 2) result = 300 + dup_idx2 * 10 + dup_idx1;
	else if (dup == 1) result = 200 + dup_idx1;
	else result = 100 + maxi;
	cout << result;
	system("pause");
	return 0;
}