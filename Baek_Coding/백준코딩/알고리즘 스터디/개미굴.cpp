#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node{
	map<string, Node*> child;
	map<string, Node*>::iterator iter;
	void insert(vector<string> v, int idx) {
		if (idx == v.size()) return;
		string ss = v[idx];
		iter = child.find(ss);		//Node
		if (iter != child.end()) 		//이미 있는 경우
			iter->second->insert(v, idx + 1);
		else {
			Node* n = new Node;
			child.insert({ ss,n });
			n->insert(v, idx + 1);
		}
	}
	void print(int idx) {
		if (child.empty()) return;
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++)
				cout << "--";
			cout << it->first << '\n';
			it->second->print(idx + 1);
		}
	}
};
Node tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, val;
	Node* root = new Node;
	string ss;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> val;
		vector<string> v;
		for (int j = 0; j < val; j++) {
			cin >> ss;
			v.push_back(ss);
		}
		root->insert(v, 0);
	}
	root->print(0);
	return 0;
}