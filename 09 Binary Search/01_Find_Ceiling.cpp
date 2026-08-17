// gfg problem name: Find Ceiling in a Sorted Array
// description: Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x. Write efficient functions to find ceiling of x in arr[].
// time complexity: O(log n)
// space complexity: O(1)
// difficulty: Easy

class Solution {
	public:
	int findCeil(vector<int>& arr, int x) {
		// code here
		int low = 0;
		int high = arr.size() - 1;
		int result = 0;
		bool found = false;
		while (low <= high)
			{
			int mid = (low + high) / 2;
			if (arr[mid] >= x)
				{
				found = true;
				result = mid;
				high = mid - 1;
			}
			else if (arr[mid] < x)
				{
				low = mid + 1;
			}
		}
		if(found) return result;
		else return -1;

	}
};
