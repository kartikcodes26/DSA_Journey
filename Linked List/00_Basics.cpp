#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main()
{
    // Creating a node
    node* first = new node();
    first->data = 10;


    node* second = new node();
    second->data = 20;


    first->next = second;
    second->next = nullptr;

    // Iterating over a list
    node *head = first;

    node *temp = head;
    while(temp != nullptr)
    {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << '\n';

    // Adding a new node to the start
    node *put = new node();
    put->data = 500;
    put->next = first;

    head = put;

    temp = head;
    while(temp != nullptr)
    {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << '\n';

    // Adding a new node to the second position
    node *d2 = new node();
    d2->data = 300;
    head->next = d2;
    d2->next = first;

    temp = head;
    while(temp != nullptr)
    {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << '\n';
    // Insert a node at last
    node *d3 = new node();
    d3->data = 700;
    second->next = d3;
    d3->next = nullptr;

    temp = head;
    while(temp != nullptr)
    {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }

}
