// Leetcode Problem 1046: Last Stone Weight
// link : https://leetcode.com/problems/last-stone-weight/
// TC : O(nlogn) SC: O(n)
// difficulty : Easy
// pattern : Heap

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x,y;
        priority_queue<int> pq;
        bool oneRemaining = false;
        for(auto ele : stones)
        {
            pq.push(ele);
        }

        while(!pq.empty())
        {
            y = pq.top();
            pq.pop();

            if(pq.empty())
            {
                oneRemaining = true;
                break;
            }

            x = pq.top();
            pq.pop();

            if(x != y)
            {
                y = y - x;
                pq.push(y);
            }
        }

        return oneRemaining ? y : 0;

    }
};
