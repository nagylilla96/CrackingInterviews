#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)

void urlify(string url, int trueLen) {
	int len = url.size();
	int i = trueLen - 1, j = len - 1;
	while (i >= 0 && j >= 0) {
		if (url[i] != ' ') {
			url[j] = url[i];
			i--;
			j--;
		}
		else {
			url[j] = '0';
			url[--j] = '2';
			url[--j] = '%';
			j--;
			i--;
		}
		if (i == j) goto end;
	}
end:
	cout << url << endl;
}


int main() {
	string str = "Mr John Smith    ";
	urlify(str, 13);
	getchar();
	return 0;
}