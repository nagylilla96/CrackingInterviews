#include <iostream>
#include <unordered_map>
using namespace std;

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

	void removeDuplicates() {
		unordered_map<int, int> umap;

		if (NULL == first) {
			return;
		}

		Node* current = first;
		while (current != NULL) {
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
		cout << "After deleting the duplicates:" << endl;
		print();
	}
};

int main() {
	LinkedList* list = new LinkedList();
	list->insert(new Node(1));
	list->insert(new Node(2));
	list->insert(new Node(2));
	list->insert(new Node(3));
	list->insert(new Node(1));
	list->insert(new Node(4));
	list->print();
	list->removeDuplicates();
	getchar();
}