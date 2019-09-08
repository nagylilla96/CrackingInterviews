#include <iostream>
using namespace std;

// Exercise 4.2

class Node {
public:
	int value;
	Node* left = NULL;
	Node* right = NULL;

	Node(int key) {
		value = key;
	}
};

class Tree {
public:
	Node* root = NULL;

	Node* add(Node* node, int key) {
		if (root == NULL) {
			root = new Node(key);
			return root;
		}

		if (node == NULL) {
			return new Node(key);
		}

		if (key < node->value) {
			node->left = add(node->left, key);
			return node;
		}

		node->right = add(node->right, key);
		return node;
	}

	void print(Node* node, int level) {
		if (node == NULL) return;
		print(node->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << "    ";
		}
		cout << node->value << endl;
		print(node->left, level + 1);
	}

	void vectorToBalanced(int vector[], int start, int end) {
		if (start > end) {
			return;
		}
		int middle = (start + end) / 2;
		root = add(root, vector[middle]);
		vectorToBalanced(vector, start, middle - 1);
		vectorToBalanced(vector, middle + 1, end);
	}
};

class Test {
public:
	void test() {
		Tree* tree = new Tree();
		int vector[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		tree->vectorToBalanced(vector, 0, 8);
		tree->print(tree->root, 0);
	}
};

int main() {
	Test* test = new Test();
	test->test();
	getchar();
}