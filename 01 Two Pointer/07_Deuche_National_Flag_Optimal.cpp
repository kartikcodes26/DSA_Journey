// Geeks for geeks 3. Deuche National Flag Problem

// Full question statement: Given an array which has only 0, 1 and 2. Sort the array without using any sorting algorithm.

class Solution {
	public:
	void sort012(vector<int>& arr) {
		// code here
		if (arr.empty())
			return ;

		int low = 0;
		int mid = 0;
		int high = arr.size() - 1;

		while (mid <= high)
			{
			if (arr[mid] == 0) {
				swap(arr[mid], arr[low]);
				low++;
				mid++;
			}
			else if (arr[mid] == 1) {
				mid++;
			}
			else if (arr[mid] == 2) {
				swap(arr[mid], arr[high]);
				high--;
			}
		}
	}
};
// Time Complexity : O(n)
// Space Complexity : O(1)
