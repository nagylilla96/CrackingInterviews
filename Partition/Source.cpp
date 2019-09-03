#include <iostream>
#include <unordered_map>
using namespace std;

// Chapter 2, exercise 4: list partitioning around an element
// EXAMPLE
//		Input:
//			3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1[partition = 5]
//		Output:
//			3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

// A node structure
class Node {
public:
	Node* next = NULL;
	int value;

	Node(int val) {
		value = val;
	}
};

class LinkedList {
public:
	Node* first = NULL;

	// Insert a node into the linked list
	void insert(Node* n) {
		if (first == NULL) {
			first = n;
			return;
		}
		Node* current = first;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = n;
	}

	// Print the linked list
	void print() {
		if (first == NULL) {
			cout << "Empty list :(" << endl;
		}
		Node* current = first;
		while (current != NULL) {
			cout << current->value << " -> ";
			current = current->next;
		}
	}

	// Partition list around pivot x
	void partition(int x) {
		if (first == NULL) return;
		Node* current = first->next;
		Node* previous = first;
		while (current != NULL) {
			if (current->value < x) {
				Node *temp = current->next;
				previous->next = current->next;
				current->next = first;
				first = current;
				current = temp;
				continue;
			}
			previous = current;
			current = current->next;
		}
	}

};

// Test
int main() {
	LinkedList* list = new LinkedList();
	list->insert(new Node(3));
	list->insert(new Node(5));
	list->insert(new Node(8));
	list->insert(new Node(5));
	list->insert(new Node(10));
	list->insert(new Node(2));
	list->insert(new Node(1));
	list->print();
	list->partition(5);
	cout << "\nList after partitioning:" << endl;
	list->print();
	getchar();
}