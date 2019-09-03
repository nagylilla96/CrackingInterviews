#include <iostream>
#include <unordered_map>
using namespace std;

// Chapter 2, exercise 1: remove duplicates from a linked list
//		Method 1: in o(n) time
//		Method 2: o(1) extra space (in-place)

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

	// Delete a node
	void deleteNode(Node* n) {
		if (first == NULL) return;
		if (n == first) {
			first = n;
			n->next = first->next;
			first->next = NULL;
			free(first);
			return;
		}
		Node* prev = first;
		Node* current = first->next;
		while (current != NULL) {
			if (current == n) {
				prev->next = current->next;
				current->next = NULL;
				free(current);
				return;
			}
			prev = current;
			current = current->next;
		}
	}

	// Remove duplicates in o(n) time using a hashmap (max o(n) extra space)
	void removeDuplicates() {
		unordered_map<int, int> umap;

		if (NULL == first) {
			return;
		}

		Node* current = first;
		while (NULL != current) {
			if (!umap[current->value]) {
				umap[current->value] = 1;
			}
			else {
				Node* duplicate = current;
				current = current->next;
				deleteNode(duplicate);
				continue;
			}
			current = current->next;
		}
		cout << "\nAfter deleting the duplicates:" << endl;
		print();
	}

	// Remove duplicates using a fast pointer in o(n^2) time but o(1) extra space
	void removeDuplicates2() {
		if (NULL == first) return;

		Node* slow = first;
		while (NULL != slow) {
			Node* fast = slow->next;
			while (NULL != fast) {
				if (fast->value == slow->value) {
					deleteNode(fast);
					break;
				}
				fast = fast->next;
			}
			slow = slow->next;
		}
		cout << "\nAfter deleting the duplicates:" << endl;
		print();
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
	list->removeDuplicates2();
	getchar();
}