// Gfg problem name : Find K Pairs with Largest Sums
// link : https://practice.geeksforgeeks.org/problems/find-k-pairs-with-largest-sums/1
// TC : O(KlogK) SC : O(K)
// Difficulty : Medium
// Pattern : Heap, two pointer

class Solution {
  public:
    struct comp {
        bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
        {
            return p1.first < p2.first; //Max Heap
        }
    };

    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq; //{sum, {i, j}}
        vector<int> res;

        if (a.empty() || b.empty() || k <= 0) return res;

        int n = a.size() - 1;
        int m = b.size() - 1;

        set<pair<int, int>> vis;

        vis.insert({n, m});
        pq.push({a[n] + b[m], {n, m}});


        while(k > 0 && !pq.empty())
        {
            pair<int, int> indices = pq.top().second;
            pq.pop();

            int i = indices.first;
            int j = indices.second;
            int currSum = a[i] + b[j];

            res.push_back(currSum);


            if(i - 1 >= 0 && vis.find({i - 1, j}) == vis.end())
            {
                int nextSum = a[i - 1] + b[j];
                pq.push({nextSum, {i - 1, j}});
                vis.insert({i - 1, j});
            }
            if(j - 1 >= 0 && vis.find({i, j - 1}) == vis.end())
            {
                int nextSum = a[i] + b[j - 1];
                pq.push({nextSum, {i, j - 1}});
                vis.insert({i, j - 1});
            }

            k--;
        }

        return res;
    }
};
