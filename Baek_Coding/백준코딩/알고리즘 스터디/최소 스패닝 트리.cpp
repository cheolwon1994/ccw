#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int Parent[10001];
struct info {
	int start, end, val;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};

priority_queue<info, vector<info>, cmp> pq;

int Find_Parent(int x) {   // 노드 x의 부모를 찾는 함수
	if (Parent[x] == x) return x;
	else return Parent[x] = Find_Parent(Parent[x]);
}

bool SameParent(int x, int y) {   // 노드 x와 y가 서로 같은 부모를 갖는지 아닌지 판단해주는 함수
	x = Find_Parent(x);   
	y = Find_Parent(y);
	if (x == y) return true;      
	else return false;         
}

void Union(int x, int y) {
	x = Find_Parent(x);   
	y = Find_Parent(y);    
	if (x != y)            
		Parent[y] = x;
}
int main() {
	int v, e, start, end, val, cs, ce, cv;
	long long result = 0;
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		Parent[i] = i;
	for (int i = 0; i < e; i++) {
		cin >> start >> end >> val;
		tmp.start = start;
		tmp.end = end;
		tmp.val = val;
		pq.push(tmp);
	}
	while (!pq.empty()) {
		cs = pq.top().start;
		ce = pq.top().end;
		cv = pq.top().val;
		pq.pop();
		if (SameParent(cs, ce))
			continue;
		else
			Union(cs, ce);
		result += cv;
	}
	cout << result;
	system("pause");
	return 0;
}