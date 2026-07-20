#include <iostream>
#include <list>
using namespace std;

// Check if linked list is cyclic using slow-fast pointer
bool checkIfCyclic(list<int> &l)
{
    auto slow = l.begin();
    auto fast = l.begin();

    while(fast != null && fast -> next != null)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{

}
