// Gfg problem name : Min Cost to Connect All Houses
// Link: https://practice.geeksforgeeks.org/problems/min-cost-to-connect-all-houses/1
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Approach: Prim's Algorithm
// Difficulty: Medium
// Note: The graph is undirected and connected, so we can start from any node. Here, we start from node 0.

class Solution {
	public:
	int minCost(vector<vector<int>> & points) {
		// code here
		vector<vector<pair<int, int>> > adjL(points.size());

		// building adjacency list by connecting all nodes
		for (int i = 0; i < points.size(); i++)
			{
			for (int j = 0; j < points.size(); j++)
				{
				if (i != j)
					{
					int dist = abs(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
					adjL[i].push_back({j, dist});
					adjL[j].push_back({i, dist});
				}
			}
		}

		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > pq;
		pq.push({0, 0}); // {wt, node}
		vector<int> vis(points.size(), 0);
		int res = 0;

		while (!pq.empty())
			{
			int node = pq.top().second;
			int weight = pq.top().first;
			pq.pop();
			if (vis[node])
				continue;

			res += weight;
			vis[node] = 1;

			for (int j = 0; j < adjL[node].size(); j++)
				{
				int neigh = adjL[node][j].first;
				int w = adjL[node][j].second;

				if (!vis[neigh])
					{
					pq.push({w, neigh});
				}
			}
		}

		return res;
	}
};
