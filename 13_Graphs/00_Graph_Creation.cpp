// gfg problem name : Graph Adjacency List Traversal
// Link : https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
// Time Complexity : O(V + E)
// SC : O(V + E)
// Difficulty : Easy
// pattern : Graphs


class Solution {
	public:
	vector<vector<int>> printGraph(int V, vector<pair<int, int>> & edges) {
	    // V is number of vertices
		vector<vector<int>> res(V);

		for (auto ele : edges)
		{
			int source = ele.first;
			int destination = ele.second;

			// non-directed graph
			res[source].push_back(destination);
			res[destination].push_back(source);
		}

		return res;

	}
};
