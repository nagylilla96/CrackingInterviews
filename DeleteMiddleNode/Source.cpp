#include <iostream>
#include <unordered_map>
using namespace std;

// Chapter 2, exercise 3: delete the middle node by only having access to it (not the rest of the list too)

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

	// I wouldn't have realised this alone :sadpepe:
	void deleteMiddleNode(Node* node) {
		if (node == NULL || node == first || node->next == NULL) return;
		Node* toDelete = node->next;
		node->value = node->next->value;
		node->next = node->next->next;
		toDelete->next = NULL;
		free(toDelete);
	}
};

// Test
int main() {
	LinkedList* list = new LinkedList();
	list->insert(new Node(1));
	list->insert(new Node(2));
	Node* toDelete = new Node(5);
	list->insert(toDelete);
	list->insert(new Node(3));
	list->insert(new Node(1));
	list->insert(new Node(4));
	list->print();
	int i = 0;
	list->deleteMiddleNode(toDelete);
	cout << "\nList after deleting the middle node:\n";
	list->print();
	getchar();
}