class Solution {
	public:
	int maxSubarraySum(vector<int>& v, int k) {
		if (k < 0 || k > v.size())
			{
			return - 1;
		}

		int start = 0;
		int end = k - 1;

		int sum = 0;

		int result = INT_MIN;

		// Initial sum
		for (int i = 0; i <= end; i++)
			{
			sum += v[i];
		}

		while (end < v.size())
			{
			result = max(result, sum);
            if (end == v.size())
			{
				break;
			}

            //Shift
			start++;
			end++;

			sum -= v[start - 1];
			sum += v[end];
		}

		return result;
	}
};

//Time complexity : O(n)
// Space Complexity : O(1)
//Submitted
