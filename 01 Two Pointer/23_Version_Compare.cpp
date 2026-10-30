// Leetcode 165. Compare Version Numbers
// link : https://leetcode.com/problems/compare-version-numbers/
// TC : O(n) SC: O(n)
// difficulty : Easy
// pattern : Two Pointer, string manipulation

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        istringstream iss1(version1), iss2(version2);
        string token;

        while(getline(iss1, token, '.'))
        {
            v1.push_back(stoi(token));
        }
        while(getline(iss2, token, '.'))
        {
            v2.push_back(stoi(token));
        }

        int val1, val2;

        for(int i = 0; i < max(version1.size(), version2.size()); i++)
        {
            val1 = i < v1.size() ? v1[i] : 0;
            val2 = i < v2.size() ? v2[i] : 0;

            if(val1 < val2) return -1;
            else if(val1 > val2) return 1;
        }
        return 0;
    }
};
