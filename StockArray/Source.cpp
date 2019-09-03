#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	int isSorted(vector<int>& vec, int start, int end) {
		if (vec.size() <= end) end = vec.size() - 1;
		for (int i = start; i < end; i++) {
			if (vec[i + 1] < vec[i]) {
				return 0;
			}
		}

		return 1;
	}

    int maxProfit(vector<int>& prices) {
		int size = prices.size();
		int sum = 0, ind = 0;
		if (size == 0) return 0;
		while (ind < size - 1) {
			int incr = 1;
			while (ind + incr < size && isSorted(prices, ind, ind + incr) == 1) {
				incr++;
			}
			sum += prices[ind + incr - 1] - prices[ind];
			ind += incr;
		}
		return sum;
    }
};

int main() {
    Solution sol = Solution();
	int arr[] = { 6,1,3,2,4,7 };
	std::vector<int> prices(arr, arr + 6);
    cout << sol.maxProfit(prices) << endl;
	getchar();
}