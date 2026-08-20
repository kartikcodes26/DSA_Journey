

/*
    Problem Name: Task Scheduler
    LeetCode No: 621

    Description:
    You are given a list of CPU tasks, each represented by a letter A to Z,
    and a cooling interval n. Each cycle, the CPU can run one task. After
    running a task, the same task cannot be run again until n units of time
    pass (cooldown period). Return the minimum number of time units required
    to execute all tasks.

    Example:
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation:
    A -> B -> idle -> A -> B -> idle -> A -> B
    The schedule uses 8 units.

    Another Example:
    Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F"], n = 2
    Output: 16

    Time Complexity: O(m log k), where m is the number of tasks processed and k is
    the number of distinct task types. In this implementation, heap operations and
    repopulation make it efficient for the given constraints.

    Space Complexity: O(k), where k is the number of distinct task types (hash map
    + priority queue). Extra vectors are used for temporary task reinsertions.

    Difficulty: Medium

    Pattern: Heap + Greedy + HashMap / Priority Queue
*/

struct cmp
{
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        if(p1.second != p2.second)
        {
            return p1.second < p2.second; // Max Heap
        }
        return p1.first > p2.first; // Max Heap (Dosent Matter)
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> pq;
        unordered_map<char, int> mp;
        unordered_map<char, int> free;
        vector<pair<char, int>> vec;
        int seat = 0;

        for(auto ele : tasks)
        {
            mp[ele]++;
            free[ele] = 0; // Next Free Seat
        }

        for(auto ele : mp)
        {
            pq.push(ele);
        }

        while(!pq.empty())
        {
            bool executed = false;

            while(!pq.empty()) // Tab tak chalo jab tak koi aa na jaye ya pq empty ho jaye
            {
                pair<char, int> c = pq.top();
                pq.pop();

                if(seat >= free[c.first])
                {
                    free[c.first] = seat + n + 1; // Next Possible seat update
                    seat++;
                    c.second--;
                    if(c.second != 0) pq.push(c);
                    executed = true;
                    break; // Koi aa gya
                }
                else
                {
                    vec.push_back(c); //  Save for repopulating
                }
            }

            if(!executed)  // Agar pq empty hone ke vajah se khula matlab koi execute nahi paya
            {
                seat++; // Vacant seat
            }

            // Repopulate Heap
            if(!vec.empty())
            {
                for(auto ele : vec)
                {
                    if(ele.second > 0)
                    {
                        pq.push(ele);
                    }
                }
                vec.clear(); // Clean vec for future use
            }
        }
        return seat;

    }
};
