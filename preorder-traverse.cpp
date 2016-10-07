#include "iostream"
#include "stack"
#include "set"

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int val_):val(val_) {
		left = nullptr;
		right = nullptr;
	}
};

void preorder_traverse(Node* root) {
	Node* cur = root;
	stack<Node*> stack;
	if (root) {
		stack.push(root);
		while(!stack.empty()) {
			cur = stack.top();
			if (cur) {
				stack.pop();
				cout << cur->val <<endl;
				if (cur->right) stack.push(cur->right);
				if (cur->left) stack.push(cur->left);
			}
		}
	}
}

int main() {
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	Node* node6 = new Node(6);
	Node* node7 = new Node(7);
	Node* node8 = new Node(8);
	Node* node9 = new Node(9);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	node4->left = node8;
	node4->right = node9;
	preorder_traverse(node1);
	return 0;
}