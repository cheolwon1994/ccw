#include <iostream>
using namespace std;
struct Node{
	char val;
	Node* l;
	Node* r;
};
Node Tree[27];
int node;

void preorder(Node* n) {
	cout << n->val;
	if (n->l != NULL) 	preorder(n->l);
	if (n->r != NULL) 	preorder(n->r);
}

void inorder(Node* n) {
	if (n->l != NULL) 	inorder(n->l);
	cout << n->val;
	if (n->r != NULL) 	inorder(n->r);
}

void postorder(Node* n) {
	if (n->l != NULL) 	postorder(n->l);
	if (n->r != NULL) 	postorder(n->r);
	cout << n->val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node;
	for (int i = 0; i < node; i++) {
		Tree[i].l = NULL;
		Tree[i].r = NULL;
		Tree[i].val = i + 'A';
	}
	for (int i = 0; i < node; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.')	Tree[a - 'A'].l = &Tree[b - 'A'];
		if (c != '.')	Tree[a - 'A'].r = &Tree[c - 'A'];
	}
	preorder(&Tree[0]);
	cout << '\n';
	inorder(&Tree[0]);
	cout << '\n';
	postorder(&Tree[0]);
	return 0;
}