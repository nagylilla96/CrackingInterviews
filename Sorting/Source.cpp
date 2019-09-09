#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
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

// Exercise 10.2
string sortString(string a) {
	string b = a;
	sort(b.begin(), b.end());
	return b;
}

void orderStrings(vector<string> &strings) {
	unordered_map<string, vector<string>> dict;

	for (auto &s : strings) {
		dict[sortString(s)].push_back(s);
	}

	strings.clear();

	for (auto &x: dict) {
		for (auto &s : x.second) {
			strings.push_back(s);
		}
	}

	for (auto &s : strings) {
		cout << s << " ";
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

	vector<string> strings;
	strings.push_back("nana");
	strings.push_back("anna");
	strings.push_back("mama");
	strings.push_back("amma");
	strings.push_back("laba");
	orderStrings(strings);
	getchar();
}