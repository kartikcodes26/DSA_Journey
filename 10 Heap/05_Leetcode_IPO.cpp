// Leetcode problem no 502
// TC : O(nlogn)
// SC : O(n)
// diff : Hard

struct cmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if(p1.first != p2.first)
        {
            return p1.first < p2.first; // Max heap
        }
        return p1.second > p2.second; // Min heap (Dosent matter)
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<pair<int,int>> p;
        int net_w = w;

        for(int i = 0; i < profits.size(); i++)
        {
            p.push_back({profits[i], capital[i]});
        }

        sort(p.begin(), p.end(),
        [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int i = 0;
        int counter = k;

        while(counter != 0)
        {
            while(i < p.size() && p[i].second <= net_w)
            {
                pq.push(p[i]);
                i++;
            }
            if(pq.empty()) break;
            net_w += pq.top().first;
            pq.pop();
            counter--;
        }

        return net_w;
    }
};
