#include <iostream>
#include <vector>
using namespace std;

// Exercise 3.1

class Stack {
	int limit = 100;
	int* stack = (int*)malloc(sizeof(int) * 3 * limit);
	int index[3] = { 0, 100, 200 };
	int elements[3] = { 0, 100, 200 };

public:
	void push(int stack_no, int x) {
		if (elements[stack_no - 1] == stack_no * limit) {
			limit *= 2;
			if (NULL == (int*)realloc(stack, 3 * limit)) {
				cout << "Could not allocate more memory than " << limit << endl;
				return;
			}
			memcpy(&stack[2 * index[2]], &stack[index[2]], (limit / 2) * sizeof(int));
			index[2] *= 2;
			elements[2] += limit;
			memcpy(&stack[2 * index[1]], &stack[index[1]], (limit / 2) * sizeof(int));
			index[1] *= 2;
			elements[1] += (limit / 2);
		}
		stack[elements[--stack_no]] = x;
		elements[stack_no]++;
	}

	void pop(int stack_no) {
		if (elements[--stack_no] == index[stack_no]) return;
		stack[elements[stack_no]] = 0;
		elements[stack_no]--;
	}

	int peek(int stack_no) {
		if (elements == 0) return -1;
		return stack[elements[--stack_no] - 1];
	}

	bool isEmpty(int stack_no) {
		return (elements[--stack_no] == 0);
	}

	void printElements(int stack_no) {
		for (int i = index[stack_no - 1]; i < elements[stack_no - 1]; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};

void test(int stack_no, Stack &myStack) {
	myStack.push(stack_no, 2);
	myStack.push(stack_no, 1);
	myStack.push(stack_no, 4);
	myStack.printElements(stack_no);
	myStack.pop(stack_no);
	myStack.printElements(stack_no);
	myStack.pop(stack_no);
	myStack.pop(stack_no);
	myStack.printElements(stack_no);
	myStack.pop(stack_no);
	(myStack.isEmpty(stack_no)) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.push(stack_no,69);
	(myStack.isEmpty(stack_no)) ? cout << "Empty\n" : cout << "Not empty\n";
	myStack.printElements(stack_no);
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void test101(Stack &myStack) {
	for (int i = 0; i < 50; i++) {
		myStack.push(1, i);
	}
	myStack.printElements(1);
	for (int i = 0; i < 50; i++) {
		myStack.push(2, i);
	}
	myStack.printElements(2);
	for (int i = 0; i < 50; i++) {
		myStack.push(3, i);
	}
	myStack.printElements(3);
	for (int i = 0; i < 100; i++) {
		myStack.push(1, i);
	}
	myStack.printElements(1);
	myStack.printElements(2);
	myStack.printElements(3);
}

int main() {
	Stack myStack = Stack();
	test101(myStack);
	getchar();
}