#include <iostream>
#include <unordered_map>
using namespace std;

// Chapter 2, exercise 5: sum two linked lists
// EXAMPLE - lists in reverse order
//		Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
//		Output: 2 -> 1 -> 9. That is, 912.
// EXAMPLE - lists in normal order
//		Input:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
//		Output : 9 - > 1 -> 2. That is, 912.

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
	int lenght = 0;

	// Insert a node into the linked list
	void insert(Node* n) {
		if (first == NULL) {
			first = n;
			lenght++;
			return;
		}
		Node* current = first;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = n;
		lenght++;
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

	// Main example (lists in reverse order)
	LinkedList* add(LinkedList* list) {
		LinkedList* result = new LinkedList();
		Node* nodeA = first;
		Node* nodeB = list->first;
		int carry = 0;

		while (nodeA || nodeB) {
			int sum = carry;
			sum += nodeA ? nodeA->value : 0;
			sum += nodeB ? nodeB->value : 0;
			result->insert(new Node(sum % 10));
			carry = sum / 10;
			nodeA = nodeA ? nodeA->next : NULL;
			nodeB = nodeB ? nodeB->next : NULL;
		}

		if (carry != 0) {
			result->insert(new Node(carry));
		}

		return result;
	}

	// Adds two nodes to each other, saves the carry, returns new node
	Node* addNode(Node* nodeA, Node* nodeB, int &carry) {
		int sum = carry;
		sum += nodeA ? nodeA->value : 0;
		sum += nodeB ? nodeB->value : 0;
		if (sum == 0) return NULL;
		Node* result = new Node(sum % 10);
		carry = sum / 10;
		return result;
	}

	// Recursive add function
	Node* recursiveAdd(Node* nodeA, Node* nodeB, int &carry) {
		if (!nodeA && !nodeB) return NULL;
		Node* node = recursiveAdd(nodeA->next, nodeB->next, carry);
		Node* result = addNode(nodeA, nodeB, carry);
		result->next = node;
		return result;
	}

	// Equalizes the lists (first represents the first node of the smaller list)
	void equalize(int &smaller, int &bigger, Node** first) {
		while (smaller != bigger) {
			Node* empty = new Node(0);
			empty->next = *first;
			*first = empty;
			smaller++;
		}
	}

	// Equalizes linked lists and then calls the recursive add function
	LinkedList* addNormal(LinkedList* listB) {
		int carry = 0, lenA = 0, lenB = 0;
		if (listB == NULL) return NULL;
		LinkedList* result = new LinkedList();
		Node** temp = NULL;
		if (lenght < listB->lenght) {
			equalize(lenght, listB->lenght, &first);
		}
		else {
			equalize(listB->lenght, lenght, &listB->first);
		}
		Node* listR = recursiveAdd(first, listB->first, carry);
		if (carry != 0) {
			Node* extra = new Node(carry);
			extra->next = listR;
			result->first = extra;
			return result;
		}
		result->first = listR;
		return result;
	}
};

// Test
int main() {
	LinkedList* list1 = new LinkedList();
	list1->insert(new Node(6));
	//list1->insert(new Node(1));
	//list1->insert(new Node(7));
	LinkedList* list2 = new LinkedList();
	list2->insert(new Node(2));
	list2->insert(new Node(9));
	list2->insert(new Node(5));
	int carry = 0;
	LinkedList* result = list1->addNormal(list2);
	result->print();
	getchar();
}