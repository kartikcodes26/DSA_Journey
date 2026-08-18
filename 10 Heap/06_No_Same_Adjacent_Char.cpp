// Leetcode 767. Reorganize String
// problem description link : https://leetcode.com/problems/reorganize-string/description/
// time complexity : O(nlogn)
// space complexity : O(n)
// difficulty : medium
// pattern : heap

struct cmp
{
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        if(p1.second != p2.second)
        {
            return p1.second < p2.second; // Max heap
        }
        return p1.first < p2.first; // Max heap (dosent matter)
    }
};



class Solution {
public:
    string reorganizeString(string s) {

        // a : 3
        // b : 2
        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> pq;
        unordered_map<char, int> mp;
        string res = "";
        for(auto ele : s)
        {
            mp[ele]++;
        }

        for(auto ele : mp)
        {
            pq.push(ele);
        }

        int i = 0;
        while(!pq.empty())
        {
            pair<char, int> p1 = pq.top();
            pq.pop();
            if(res.empty() || res[i - 1] != p1.first)
            {
                res.push_back(p1.first);

                p1.second--;
                if(p1.second > 0)
                {
                    pq.push(p1);
                }
            }
            else
            {
                if(pq.empty()) return "";

                pair<char, int> p2 = pq.top();
                pq.pop();
                res.push_back(p2.first);
                p2.second--;
                if(p2.second != 0) pq.push(p2);
                pq.push(p1);

            }
            i++;
        }
        return res;
    }
};
