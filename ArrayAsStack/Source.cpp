#include <iostream>
#include <vector>
using namespace std;

class Stack {
	int limit = 100;
	int* stack = (int*)malloc(sizeof(int) * limit);
	int elements = 0;

public:
	void push(int x) {
		if (elements == limit) {
			limit *= 2;
			if (NULL == (int*)realloc(stack, limit)) {
				cout << "Could not allocate more memory than " << limit << endl;
			}
		}
		stack[elements] = x;
		elements++;
	}

	void pop() {
		if (elements == 0) return;
		stack[elements - 1] = 0;
		elements--;
	}

	int peek() {
		if (elements == 0) return -1;
		return stack[elements - 1];
	}

	bool isEmpty() {
		return (elements == 0);
	}

	void printElements() {
		cout << endl;
		for (int i = 0; i < elements; i++) {
			cout << stack[i] << " ";
		}
	}
};

int main() {
	Stack myStack = Stack();
	myStack.push(2);
	myStack.push(1);
	myStack.push(4);
	myStack.printElements();
	myStack.pop();
	myStack.printElements();
	myStack.pop();
	myStack.pop();
	myStack.printElements();
	myStack.pop();
	(myStack.isEmpty()) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.push(69);
	(myStack.isEmpty()) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.printElements();
	getchar();
}