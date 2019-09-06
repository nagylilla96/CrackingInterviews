#include <iostream>
#include <vector>
using namespace std;

// Exercise 3.2

class Node {
public:
	int value;
	Node* min = NULL;

	Node(int val) {
		value = val;
	}
};

class Stack {
	int limit = 100;
	Node* stack = (Node*)malloc(sizeof(Node) * limit);
	int elements = 0;
	Node* min_node = new Node(INT_MAX);

public:
	void push(Node* x) {
		if (elements == limit) {
			limit *= 2;
			if (NULL == (int*)realloc(stack, limit)) {
				cout << "Could not allocate more memory than " << limit << endl;
				return;
			}
		}
		x->min = min_node;
		if (x->value < min_node->value) {
			min_node = x;
		}
		stack[elements] = *x;
		elements++;
	}

	void pop() {
		if (elements == 0)
		{
			min_node->value = INT_MAX;
			return;
		}
		if (stack[--elements].value == min_node->value) {
			min_node = stack[elements].min;
		}
		stack[elements] = NULL;
	}

	Node* peek() {
		if (elements == 0) return NULL;
		return &stack[elements - 1];
	}

	Node* minElement() {
		if (elements == 0) return NULL;
		return min_node;
	}

	bool isEmpty() {
		return (elements == 0);
	}

	void printElements() {
		cout << endl;
		for (int i = 0; i < elements; i++) {
			cout << stack[i].value << " ";
		}
	}

	void printMin() {
		if (minElement()) {
			cout << "\nMin: " << minElement()->value;
		}
		else {
			cout << "\nMin is NULL!";
		}
	}
};


int main() {
	Stack myStack = Stack();
	myStack.push(new Node(2));
	myStack.printMin();
	myStack.push(new Node(1));
	myStack.printMin();
	myStack.push(new Node(4));
	myStack.printMin();
	myStack.printElements();
	myStack.pop();
	myStack.printElements();
	myStack.pop();
	myStack.printMin();
	myStack.pop();
	myStack.printMin();
	myStack.printElements();
	myStack.pop();
	(myStack.isEmpty()) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.push(new Node(69));
	(myStack.isEmpty()) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.printElements();
	myStack.printMin();
	getchar();
}