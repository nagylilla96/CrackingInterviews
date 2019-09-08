#include <iostream>
#include <queue>
using namespace std;

// Exercise 4.1

class Node {
public:
	int value;
	Node* next = NULL;
	bool marked = false;

	Node(int val) {
		value = val;
	}
};

class Graph {
	// Node** nodes represents the adjacency list
	Node** nodes = (Node**)calloc(10, sizeof(Node*));
	int size;

public:
	Graph(int size) {
		this->size = size;
	}

	// Add new node to adjacency list
	// TODO: reallocation of the array if size > 10
	void add(int index, Node* node) {
		if (nodes[index] == NULL) {
			nodes[index] = node;
			return;
		}
		Node* curr = nodes[index];
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = node;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			Node* curr = nodes[i];
			cout << i << ": ";
			while (curr != NULL) {
				cout << curr->value << " ";
				curr = curr->next;
			}
			cout << endl;
		}
		cout << endl;
	}

	// BFS - find route between a and b
	bool isRoute(Node* a, Node* b) {
		queue<Node*> Q;
		a->marked = true;
		Q.push(a);

		while (!Q.empty()) {
			Node* node = Q.front();
			Q.pop();
			if (nodes[node->value] == NULL) return false;
			Node* curr = nodes[node->value];
			while (curr != NULL) {
				if (!curr->marked) {
					if (b->value == curr->value) return true;
					curr->marked = true;
					Q.push(curr);
				}
				curr = curr->next;
			}
		}
	}
};

class Test {
	Graph* graph;

public:
	// Test creating the graph
	void fillGraph() {
		graph = new Graph(6);
		graph->add(0, new Node(4));
		graph->add(0, new Node(5));
		graph->add(1, new Node(0));
		graph->add(2, new Node(1));
		graph->add(2, new Node(3));
		graph->add(4, new Node(1));
		graph->add(4, new Node(2));
		graph->add(4, new Node(3));
		graph->print();
	}

	// Test isRoute function
	void isRoute() {
		if (graph->isRoute(&Node(5), &Node(3))) {
			cout << "True";
			return;
		}
		cout << "False";
	}
};

int main() {
	Test* test = new Test();
	test->fillGraph();
	test->isRoute();
	getchar();
}