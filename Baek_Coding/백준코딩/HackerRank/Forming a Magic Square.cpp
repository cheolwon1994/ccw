int cnt[10];
int ans = 36;
int check[4][2] = { {1,9},{2,8},{3,7},{4,6} };
int xy[8] = { 0,1,2,5,8,7,6,3 };
bool flag[4] = { false, };
// Complete the formingMagicSquare function below.

void dfs(vector<vector<int>> s, int idx, int cnt) {
	if (idx == 4) {
		bool avail = true;
		for (int i = 0; i < 3; i++) {
			if (s[0][i] + s[1][i] + s[2][i] != 15) {
				avail = false;
				break;
			}
			if (s[i][0] + s[i][1] + s[i][2] != 15) {
				avail = false;
				break;
			}
		}
		if (avail) 
			ans = min(ans, cnt);		
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (flag[i]) continue;
		//중앙기준으로 대칭점
		int a = s[xy[idx] / 3][xy[idx] % 3];
		int b = s[xy[idx + 4] / 3][xy[idx + 4] % 3];
		
		flag[i] = true;
		int temp = abs(a - check[i][0]) + abs(b - check[i][1]);
		s[xy[idx] / 3][xy[idx] % 3] = check[i][0];
		s[xy[idx + 4] / 3][xy[idx + 4] % 3] = check[i][1];
		dfs(s, idx + 1, cnt + temp);

		s[xy[idx] / 3][xy[idx] % 3] = check[i][1];
		s[xy[idx + 4] / 3][xy[idx + 4] % 3] = check[i][0];
		temp = abs(a - check[i][1]) + abs(b - check[i][0]);
		dfs(s, idx + 1, cnt + temp);

		s[xy[idx] / 3][xy[idx] % 3] = a;
		s[xy[idx + 4] / 3][xy[idx + 4] % 3] = b;
		flag[i] = false;
	}
}

int formingMagicSquare(vector<vector<int>> s) {	
	int vv = s[1][1];
	if (vv != 5) 
		s[1][1] = 5;	
	dfs(s, 0, abs(vv - 5)); //중앙은 무조건 0
	return ans;
}