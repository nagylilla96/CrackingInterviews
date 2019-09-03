#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void print(vector<int>& nums) {
		for (auto n : nums) {
			cout << n << " ";
		}
		cout << endl;
	}

	void rotate(vector<int>& nums, int k) {
		if (k <= 0) return;
		int size = nums.size();
		if (0 == size) return;
		int index = 0, next = nums[0];
		int* added = (int*)calloc(size, sizeof(int));
		int turn = 0;
		for (int i = 0; i < size; i++) {
			if (index >= size) {
				index %= size;
			}
			if (added[index] == 1) {
				turn++;
				next = nums[(size - k + turn) % size];
				index = (size - k + turn) % size;
			}
			added[index] = 1;
			int current = nums[(index + k) % size];
			nums[(index + k) % size] = next;
			next = current;
			index += k;
		}
		print(nums);
		free(added);
	}
};

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(int);
	vector<int> nums(arr, arr + n);
	Solution sol = Solution();
	sol.rotate(nums, 3);
	getchar();
}