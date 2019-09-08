#include <iostream>
#include <string>
using namespace std;

// Bit manipulation exercises (chapter 5)

bool exercise1(int &n, int m, int i, int j) {
	// i has to be smaller than j, if not, swap them
	if (i > j) {
		int temp = i;
		i = j;
		j = temp;
	}
	// if the number of bits in m isn't equal to the number of bits between i and j,
	// it means that m wouldn't fit between the ith and jth bit
	if ((m >> (j - i + 1)) != 0) return false;
	// temp1 is the left hand side of the mask (0s to the jth bit)
	int temp1 = ~((1 << (j + 1)) - 1);
	// temp2 is the right hand side of the mask (1s to the ith bit)
	int temp2 = (1 << i) - 1;
	// merge the masks into pad
	int pad = -1 & temp1 | temp2;
	// clear the right bits of n (where there are 0s in the pad)
	n = n & pad;
	// in the place of the zeroes, put the bits from m
	n = n | (m << i);
	return true;
}

string exercise2(double num) {
	if (num >= 1 || num <= 0) return "ERROR";

	string number = "0.";

	while (num != 0) {
		if (number.length() >= 32) {
			return "ERROR";
		}
		double temp = num * 2;
		if (temp >= 1) {
			number += "1";
			num = temp - 1;
		}
		else {
			number += "0";
			num = temp;
		}
	}
	return number;
}

int main() {
	int n = 1024;
	if (!exercise1(n, 19, 2, 6)) cout << "1. FALSE";
	else cout << "1. " << n;
	cout << "\n2. " << exercise2(0.625) << endl;
	getchar();
	return 0;
}