// Leetcode no 759. Employee Free Time
// Link : https://leetcode.com/problems/employee-free-time/
// TC : O(nlogn) where n is the number of intervals
// SC : O(n) where n is the number of intervals
// difficulty : hard
// Pattern : Greedy, Sorting, Merge Intervals
// Note : This problem is similar to 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
        vector<vector<int>> simplified;

        // Step 1: Flatten all employees' schedules
        for (auto ele : schedule) {
            for (auto e : ele) {
                simplified.push_back(e);
            }
        }

        // Step 2: Sort intervals by start time
        sort(simplified.begin(), simplified.end());

        // Step 3: Merge overlapping intervals
        vector<vector<int>> merged;

        int start1 = simplified[0][0];
        int end1 = simplified[0][1];

        for (int i = 1; i < simplified.size(); i++) {
            int start2 = simplified[i][0];
            int end2 = simplified[i][1];

            if (start2 <= end1) {
                // Overlapping intervals: extend the current interval
                end1 = max(end1, end2);
            }
            else {
                // No overlap: save the current busy interval
                merged.push_back({start1, end1});

                start1 = start2;
                end1 = end2;
            }
        }

        // Save the final merged interval
        merged.push_back({start1, end1});

        // Step 4: Gaps between merged intervals are free time
        vector<vector<int>> result;

        for (int i = 0; i + 1 < merged.size(); i++) {
            result.push_back({merged[i][1], merged[i + 1][0]});
        }

        return result;
    }
};
