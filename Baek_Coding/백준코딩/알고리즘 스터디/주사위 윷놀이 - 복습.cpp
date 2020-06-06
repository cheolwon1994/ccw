#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[6][21] = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{10,13,16,19,25},
	{20,22,24,25},
	{30,28,27,26,25},
	{25,30,35,40},
	{40,0}
};

struct info {
	int lev, idx;
};
info tmp;
vector<int> v;
int number[10], result = 0;
info player[4];

void play() {
	int t_result = 0;
	for (int i = 0; i < 4; i++) {
		player[i].idx = 0;
		player[i].lev = 0;
	}
	bool finish = true;
	int nl, nidx, next;		//다음 층, 다음 위치
	for (int i = 0; i < v.size(); i++) {
		int dice = number[i];
		int pl = player[v[i]].lev;
		int pidx = player[v[i]].idx;
		if (pl == 5 && pidx == 1) continue;		//도착지점
		next = dice + pidx;
		if (pl == 0) {
			if (next == 5) {
				nl = 1;
				nidx = 0;
			}
			else if (next == 10) {
				nl = 2;
				nidx = 0;
			}
			else if (next == 15) {
				nl = 3;
				nidx = 0;
			}
			else if (next == 20) {
				nl = 5;
				nidx = 0;
			}
			else if (next > 20) {
				nl = 5;
				nidx = 1;
			}
			else {
				nl = pl;
				nidx = next;
			}
		}
		else if (pl == 1 || pl==3) {
			if (next < 4) {
				nl = pl;
				nidx = next;
			}
			else if (4 <= next && next <= 6) {
				nl = 4;
				nidx = next - 4;
			}
			else if (next == 7) {
				nl = 5;
				nidx = 0;
			}
			else if (next == 8) {		//도착지점
				player[v[i]].idx = 1;
				player[v[i]].lev = 5;
				continue;
			}
		}
		else if (pl == 2) {
			if (next < 3) {
				nl = pl;
				nidx = next;
			}
			else if (3 <= next && next <= 5) {
				nl = 4;
				nidx = next - 3;
			}
			else if (next == 6) {
				nl = 5;
				nidx = 0;
			}
			else if (next == 7) {
				player[v[i]].idx = 1;
				player[v[i]].lev = 5;
				continue;
			}
		}
		else if (pl == 4) {
			if (next < 3) {
				nl = pl;
				nidx = next;
			}
			else if (next == 3) {
				nl = 5;
				nidx = 0;
			}
			else if (next > 3) {
				player[v[i]].idx = 1;
				player[v[i]].lev = 5;
				continue;
			}
		}
		else if (pl == 5) {		//무조건 도착지점으로 가서 점수 계산 필요x
			player[v[i]].idx = 1;
			player[v[i]].lev = 5;
			continue;			
		}
		
		for (int k = 0; k < 4; k++) {
			if (k == v[i]) continue;
			if (player[k].idx == nidx && player[k].lev == nl) {
				finish = false;
				break;
			}
		}
		if (!finish) break;
		//자리 체인지
		player[v[i]].lev = nl;
		player[v[i]].idx = nidx;
		//값 더하기
		t_result += arr[nl][nidx];		
	}
	if (finish) 	result = max(result, t_result);	
}

void dfs(int cnt) {
	if (cnt == 10) {
		play();
		return;
	}
	for (int i = 0; i < min(4, cnt+1); i++) {
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		cin >> number[i];
	dfs(0);
	cout << result;
	return 0;
}