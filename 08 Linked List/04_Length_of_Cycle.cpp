/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        bool isloop = false;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                isloop = true;
                break;
            }
        }
        if(isloop)
        {
            slow = head;
        }
        else
        {
            return 0;
        }


        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }

        int counter  = 0;
        Node *temp = slow;
        while(true)
        {
            temp = temp -> next;
            counter++;
            if(temp == slow)
            {
                return counter;
            }
        }


    }
};
