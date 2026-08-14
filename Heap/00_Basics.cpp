#include <iostream>
#include <queue>
using namespace std;


void printHeap(priority_queue<int> pq)
{
    while(!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << "\n \n";
}

void printHeap(priority_queue<int, vector<int>, greater<int>> pqm)
{
    while(!pqm.empty())
    {
        cout << pqm.top() << ' ';
        pqm.pop();
    }
    cout << "\n \n";
}

int main()
{
    // max heap syntax
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(10);
    // cout << pq.top() << '\n';
    // pq.pop();

    // min heap syntax
    printHeap(pq);
    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(5);
    pqm.push(4);
    pqm.push(10);
    // cout << pqm.top() << '\n';
    // pqm.pop();
    printHeap(pqm);

    // push -> O(logN)
    // pop -> O(logN)
    // top -> O(1)
    // where N is the number of elements in the heap



}
