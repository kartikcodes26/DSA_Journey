#include <iostream>
#include <list>
using namespace std;

void display(list<int> &l)
{
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << "\n";
}
int main()
{
    list<int> l1; // An empty list of zero size
    list<int> l2(9); // An empty list of 7 size

    l1.push_back(4);
    l1.push_back(9);
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(4);
    list<int> :: iterator it;
    display(l1);

    // Sorting the list
    l1.sort();

    // Merging the list

    l1.merge(l2);
    // l1 after merging
    display(l1);

    l1.reverse()

}
