// Leetcode Problem Name : 378. Kth Smallest Element in a Sorted Matrix
// Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// TC : O(KlogK) SC : O(K)
// Difficulty : Medium
// Pattern : Heap, two pointers, sorted matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using node = tuple<int,int,int>;
        priority_queue<node, vector<node>, greater<node>> pq; // Min heap
        bool found = false;

        for(int i = 0; i < matrix.size(); i++)
        {
            pq.push({matrix[i][0], i, 0});
        }

        while(!pq.empty())
        {
            auto [value, row, col] = pq.top();
            pq.pop();
            k--;
            if(k == 0)
            {
                return value;
            }
            if(col + 1 < matrix[0].size())
            {
                col = col + 1;
                int nextVal = matrix[row][col];
                pq.push({nextVal, row, col});
            }
        }

        return -1;
    }
};
