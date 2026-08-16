#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;


// Target max heap for first
// Min heap for second

/*
Short trick :
1) Max heap : <
2) Min heap : >
*/

struct cmp
{
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
    {
        if(p1.first != p2.first)
        {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

void printHeap(priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pqm)
{
    while(!pqm.empty())
    {
        cout << pqm.top().first << " , " << pqm.top().second;
        cout << '\n';
        pqm.pop();
    }
    cout << "\n \n";
}

int main()
{
    // Create a heap of pairs
    priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
    pq.push({7, "kartik"});
    pq.push({1, "asus"});
    pq.push({3, "vivobook"});

    printHeap(pq);

    // cmp is a custom comparator

}
