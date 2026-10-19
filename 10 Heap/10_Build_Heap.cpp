// Gfg problem : Build Heap
// link : https://practice.geeksforgeeks.org/problems/build-heap/1
// TC : O(nlogn) SC: O(n)
// difficulty : Easy
// pattern : Heap

class Solution {
  public:
    void buildHeap(vector<int>& arr) {
        priority_queue<int> pq;
        for(auto ele : arr)
        {
            pq.push(ele);
        }
        int i = 0;
        while(!pq.empty())
        {
            arr[i] = pq.top();
            pq.pop();
            i++;
        }
    }
};
