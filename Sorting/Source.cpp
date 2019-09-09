#include <iostream>
#include <vector>
using namespace std;

// Chapter 10 - woo!

// Exercise 10.1
void merge(int* a, int* b, int sizeA, int sizeB) {
	int indA = sizeA - 1;
	int indB = sizeB - 1;
	int indLast = sizeA + sizeB - 1;

	while (indB >= 0) {
		if (b[indB] < a[indA]) {
			a[indLast--] = a[indA--];
		}
		else {
			a[indLast--] = b[indB--];
		}
	}
}

void print(int* a, int sizeA) {
	for (int i = 0; i < sizeA; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[4] = { 1, 2, 3, 5 };
	int b[5] = { 1, 2, 4, 8, 9 };

	int* vecA = (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 4; i++) {
		vecA[i] = a[i];
	}
	int* vecB = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		vecB[i] = b[i];
	}
	merge(vecA, vecB, 4, 5);
	print(vecA, 9);
	getchar();
}