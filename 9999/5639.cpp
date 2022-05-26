#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if (node == nullptr) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	Node* root = new Node();
	int v;
	while (cin >> v) {
		insert(root, v);
	}
	postorder(root);
}