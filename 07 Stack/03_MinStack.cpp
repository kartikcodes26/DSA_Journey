// leetcode 155. Min Stack
// design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// time complexity: O(1)
// space complexity: O(n)
// difficulty: Easy

class MinStack {
public:
    vector<int> v;
    vector<int> mn;
    MinStack() {
    }

    void push(int value) {
        if(mn.empty())
        {
            mn.push_back(value);
        }
        else
        {
            mn.push_back(min(value, mn.back()));
        }

        v.push_back(value);
    }

    void pop() {
        v.pop_back();
        mn.pop_back();
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return mn.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
