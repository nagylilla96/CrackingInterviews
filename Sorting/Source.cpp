#include <iostream>
#include <vector>
using namespace std;

// Chapter 10 - woo!

// Exercise 10.1
void merge(vector<int>& a, vector<int> &b) {
	int indA = 0;
	int indB = 0;

	while (indA != a.size()) {
		if (b[indB] < a[indA]) {
			a.insert(a.begin() + indA, b[indB]);
			indB++;
		}
		indA++;
	}

	while (indB != b.size()) {
		a.insert(a.end(), b[indB]);
		indB++;
	}
}

void print(vector<int> &a) {
	for (auto x : a) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int a[4] = { 1, 2, 3, 5 };
	int b[5] = { 1, 2, 4, 8, 9 };
	vector<int> vecA(a, a + 4);
	vector<int> vecB(b, b + 5);

	merge(vecA, vecB);
	print(vecA);
	getchar();
}