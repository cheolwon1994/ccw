#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct info {
	int x1, x2, y1, y2;
};
info tmp;
vector<info> v;
int par[1001];

int find_parent(int x) {
	if (par[x] == x) return x;
	return par[x] = find_parent(par[x]);
}

void make_union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) par[b] = a;
	else if (a > b) par[a] = b;
}

bool meet(int i, int j) {
	info a = v[i];
	info b = v[j];
	if (b.y2 > a.y2 && a.x2 < b.x2 && a.y1 > b.y1 && b.x1 < a.x1)
		return false;
	if (a.y2 > b.y2 && b.x2 < a.x2 && b.y1 > a.y1 && b.x1 > a.x1)
		return false;
	if (b.y1 > a.y2 || b.x1 > a.x2 || a.y1 > b.y2 || b.x2 < a.x1)
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x1, x2, y1, y2, num;
	cin >> num;
	for (int i = 0; i <= num; i++)
		par[i] = i;
	//초기에 고개를 내린상태이므로 추가해야 한다
	tmp.x1 = 0;
	tmp.x2 = 0;
	tmp.y1 = 0;
	tmp.y2 = 0;
	v.push_back(tmp);
	for (int i = 1; i <= num; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		tmp.x1 = x1;
		tmp.x2 = x2;
		tmp.y1 = y1;
		tmp.y2 = y2;
		v.push_back(tmp);
	}
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j <= num; j++) {
			if (meet(i, j)) 
				make_union(i, j);		
		}
	}
	set<int> s;
	for (int i = 0; i <= num; i++)
		s.insert(find_parent(par[i]));
	cout << s.size() - 1;
	system("pause");
	return 0;
}