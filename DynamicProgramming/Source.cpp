#include <iostream>
using namespace std;

// Wow, I'm really curious how this will work out

// Exercise 8.1
int steps(int index, int n, int* memo) {
	if (index > n) return 0;

	if (index == n) return 1;

	if (memo[index] == -1) {
		memo[index] = steps(index + 1, n, memo) + steps(index + 2, n, memo) + steps(index + 3, n, memo);
	}

	return memo[index];
}

int main() {
	int n = 36;
	int* memo = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		memo[i] = -1;
	}
	cout << steps(0, n, memo) << endl;
	getchar();
}