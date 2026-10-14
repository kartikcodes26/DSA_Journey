// Leetcode no 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i/
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium
// pattern: Intervals

class MyCalendar {
public:
    vector<vector<int>> booked;
    int greatestend;
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        for(auto ele : booked)
        {
            if(startTime < ele[1] && endTime > ele[0])
            {
                return false;
            }
        }

        booked.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
