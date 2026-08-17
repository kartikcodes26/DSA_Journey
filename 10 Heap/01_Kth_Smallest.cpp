// Gfg problem name : Kth smallest element
// description : Given an array arr[] of N elements, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
// Time Complexity: O(NlogK) where N is the number of elements in the array and K is the given integer
// Space Complexity: O(K) where K is the given integer
// Difficulty Level: Medium
// Constraints:
    // 1 <= N <= 10^5
    // 1 <= arr[i] <= 10^5
    // 1 <= K <= N
//

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++)
        {
            if(arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};
