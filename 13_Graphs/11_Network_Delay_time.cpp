// Leetcode problem: 743. Network Delay Time
// difficulty : Medium
// pattern : Dijkstra's Algorithm
// TC: O(E log V)
// SC: O(V + E)
// Link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjL(n + 1); // {node , time}
        for(int i = 0; i < times.size(); i++)
        {
            int src = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adjL[src].push_back({dest, time});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {time, node} min-heap
        vector<int> res(n + 1, INT_MAX);
        pq.push({0, k});
        res[k] = 0;
        int max_time = 0;

        while(!pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(int i = 0; i < adjL[node].size(); i++)
            {
                int neigh = adjL[node][i].first;
                int ntime = adjL[node][i].second;

                if(time + ntime < res[neigh])
                {
                    res[neigh] = time + ntime;
                    pq.push({res[neigh], neigh});
                }
            }
        }

        // Check if every node was reached
        for(int i = 1; i <= n; i++)
        {
            if(res[i] == INT_MAX)
                return -1;

            max_time = max(max_time, res[i]);
        }

        return max_time;
    }
};
