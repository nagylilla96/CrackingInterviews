#include <iostream>
#include <unordered_map>
using namespace std;

// Chapter 2, exercise 2: return the kth to the last element from a linked list
//		Singly linked
//		kth to last element is (last - k) th element (it wasn't obvious, now shut up)
//		WHY THO aaaa :))) anyway

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

	// I would have never even guessed this solution, fml
	// And it's useless and inefficient
	// Cries
	Node* KthToN(Node* head, int k, int &i) {
		if (head == NULL) return NULL;

		Node* node = KthToN(head->next, k, i);
		i++;
		if (i == k) return head;
		return node;
	}
};

// Test
int main() {
	LinkedList* list = new LinkedList();
	list->insert(new Node(1));
	list->insert(new Node(2));
	list->insert(new Node(2));
	list->insert(new Node(3));
	list->insert(new Node(1));
	list->insert(new Node(4));
	list->print();
	int i = 0;
	Node* kth = list->KthToN(list->first, 3, i);
	cout << "\nThe kth node to the end is " << kth->value << endl;
	getchar();
}