#include <iostream>
#include <vector>
using namespace std;

// Exercise 3.3

class Plate {
public:
	int value;

	Plate(int i) {
		value = i;
	}
};

class Stack {
	vector<Plate*> stack;
	int limit = 10;

public:
	bool push(Plate* p) {
		if (stack.size() == limit) return false;
		stack.push_back(p);
		return true;
	}

	bool pop() {
		if (stack.empty()) return false;
		stack.pop_back();
		return true;
	}

	bool isEmpty() {
		return stack.empty();
	}

	bool isFull() {
		return (stack.size() == 10);
	}

	void printStack() {
		cout << "\nStack\n";
		for (auto p : stack) {
			cout << p->value << " ";
		}
	}
};

class SetOfStacks {
	vector<Stack*> stacks;

public:
	bool push(Plate* p) {
		if (stacks.empty()) {
			stacks.push_back(new Stack());
		}
		for (auto s : stacks) {
			if (!s->isFull()) {
				return s->push(p);
			}
		}
		stacks.push_back(new Stack());
		return stacks.back()->push(p);
	}

	bool pop() {
		if (stacks.size() == 0) return false;
		if (!stacks.back()->pop()) {
			stacks.pop_back();
		}
		return stacks.back()->pop();
	}

	bool popAt(int st) {
		if (stacks.at(st)->isEmpty()) {
			stacks.erase(stacks.begin() + st);
		}
		return stacks.at(st)->pop();
	}

	void printElements() {
		cout << endl;
		for (auto s : stacks) {
			s->printStack();
		}
	}
};

class Test {
public:
	void test1() {
		SetOfStacks* stacks = new SetOfStacks();
		for (int i = 0; i < 23; i++) {
			stacks->push(new Plate(i));
		}
		stacks->printElements();
		for (int i = 0; i < 11; i++) {
			stacks->popAt(1);
		}
		stacks->printElements();
		for (int i = 0; i < 5; i++) {
			stacks->push(new Plate(i));
		}
		stacks->printElements();
	}
	void test2() {
		SetOfStacks* stacks = new SetOfStacks();
		for (int i = 0; i < 23; i++) {
			stacks->push(new Plate(i));
		}
		stacks->printElements();
		for (int i = 0; i < 10; i++) {
			stacks->popAt(1);
		}
		stacks->printElements();
		for (int i = 0; i < 5; i++) {
			stacks->push(new Plate(i));
		}
		stacks->printElements();
	}
};


int main() {
	Test* test = new Test();
	test->test2();
	getchar();
}