#include <iostream>
#include <string>
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

#pragma warning(disable : 4996)
string temp(int row, int col) {
	char temp[10];
	sprintf(temp, "(%d, %d) ", row, col);
	return temp;
}

// Exercise 8.2 -> cancer code cause I cannot deal with strings
string robot(int posR, int posC, int r, int c, int** grid, string** visited) {
	if (posR == r - 1 && posC == c - 1) {
		visited[posR][posC] = temp(posR, posC);
		return visited[posR][posC];
	}
	if (posR >= r) return "ERROR";
	if (posC >= c) return "ERROR";
	if (grid[posR][posC] == 1) return "ERROR";
	if (visited[posR][posC].compare("") != 0) {
		return visited[posR][posC];
	}

	string str = robot(posR + 1, posC, r, c, grid, visited);
	if (str.compare("ERROR") != 0) {
		str = temp(posR, posC) + str;
		visited[posR][posC] = str;
		return str;
	}
	str = robot(posR, posC + 1, r, c, grid, visited);
	if (str.compare("ERROR") != 0) {
		str = temp(posR, posC) + str;
		visited[posR][posC] = str;
		return str;
	}
	return str;
}

// Exercise 8.3
int findMagicIndex(int start, int end, int arr[]) {
	if (start > end) return -1;

	int middle = (start + end) / 2;

	if (middle == arr[middle]) return middle;

	int sol1 = findMagicIndex(start, middle - 1, arr);
	if (sol1 != -1) return sol1;

	int sol2 = findMagicIndex(middle + 1, end, arr);
	return sol2;
}

int main() {
	int n = 36;
	int* memo = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		memo[i] = -1;
	}
	cout << steps(0, n, memo) << endl;
	int rows = 4;
	int cols = 5;
	int grid[4][5] = {
		{0, 1, 0, 0, 1},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{1, 1, 0, 0, 0}
	};
	int** copyGrind = (int**)malloc(rows * sizeof(int*));
	string** visitGrid = (string**)malloc(rows * sizeof(string*));
	for (int i = 0; i < rows; i++) {
		copyGrind[i] = (int*)malloc(cols * sizeof(int));
		visitGrid[i] = (string*)calloc(cols, sizeof(string));
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			copyGrind[i][j] = grid[i][j];
			visitGrid[i][j] += "";
		}
	}
	cout << robot(0, 0, rows, cols, copyGrind, visitGrid);
	for (int i = 0; i < rows; i++) {
		free(copyGrind[i]);
		free(visitGrid[i]);
	}
	int arr[6] = { 1, 1, 3, 4, 5, 12 };
	cout << "\n3. " << findMagicIndex(0, 5, arr) << endl;
	free(copyGrind);
	free(visitGrid);
	getchar();
}