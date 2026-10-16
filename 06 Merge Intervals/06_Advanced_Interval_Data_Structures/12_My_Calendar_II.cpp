// Leetcode 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Difficulty: Medium
// Pattern: Intervals



class MyCalendarTwo {
public:
    vector<vector<int>> intervals;
    vector<vector<int>> doubleBooked;

    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {

        for (auto ele : doubleBooked) {
            if (startTime < ele[1] && endTime > ele[0]) {
                return false;
            }
        }

        for (auto ele : intervals) {
            if (startTime < ele[1] && endTime > ele[0]) {
                int left = max(startTime, ele[0]);
                int right = min(endTime, ele[1]);

                doubleBooked.push_back({left, right});
            }
        }

        intervals.push_back({startTime, endTime});
        return true;
    }
};
