#include <iostream>
using namespace std;
struct Node {
	Node* left;
	Node* right;
	char data;
};

void preorder(Node *n) {
	cout << n->data;
	if (n->left != NULL)	preorder(n->left);
	if (n->right != NULL)	preorder(n->right);
}

void inorder(Node *n) {
	if (n->left != NULL)	inorder(n->left);
	cout << n->data;
	if (n->right != NULL)	inorder(n->right);
}

void postorder(Node *n) {
	if (n->left != NULL)	postorder(n->left);
	if (n->right != NULL)	postorder(n->right);
	cout << n->data;
}

int main() {
	int node;
	char m, l, r;
	cin >> node;
	Node Tree[26];
	for (int i = 0; i < node; i++) {
		Tree[i].data = 'A' + i;
		Tree[i].left = NULL;
		Tree[i].right = NULL;
	}
	for (int i = 0; i < node; i++) {
		cin >> m >> l >> r;
		if (l != '.')	Tree[m - 'A'].left = &Tree[l - 'A'];
		if (r != '.')	Tree[m - 'A'].right = &Tree[r - 'A'];
	}
	preorder(&Tree[0]);
	cout << endl;
	inorder(&Tree[0]);
	cout << endl;
	postorder(&Tree[0]);
	cout << endl;
	system("pause");
	return 0;
}