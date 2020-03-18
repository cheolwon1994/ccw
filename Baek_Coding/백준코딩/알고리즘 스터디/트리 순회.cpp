#include <iostream>
using namespace std;

struct node {
	node* left;
	node* right;
	char val;
};

void preorder(node* n) {
	cout << n->val;
	if (n->left != NULL)
		preorder(n->left);
	if (n->right != NULL)
		preorder(n->right);
}

void inorder(node* n) {
	if (n->left != NULL)
		inorder(n->left);
	cout << n->val;
	if (n->right != NULL)
		inorder(n->right);
}

void postorder(node* n) {
	if (n->left != NULL)
		postorder(n->left);
	if (n->right != NULL)
		postorder(n->right);
	cout << n->val;
}

int main() {
	int num;
	char m, l, r;
	node nodes[26];
	cin >> num;
	for (int i = 0; i < num; i++) {
		nodes[i].val = i+'A';
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}
	for (int i = 0; i < num; i++) {
		cin >> m >> l >> r;
		if (l != '.')	nodes[m - 'A'].left = &nodes[l - 'A'];
		if (r != '.')	nodes[m - 'A'].right = &nodes[r - 'A'];
	}
	preorder(&nodes[0]);
	cout << '\n';
	inorder(&nodes[0]);
	cout << '\n';
	postorder(&nodes[0]);
	cout << '\n';
	system("pause");
	return 0;
}