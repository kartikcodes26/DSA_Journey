// LeetCode problem no: 74
// Problem Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    // Integers in each row are sorted from left to right.
    // The first integer of each row is greater than the last integer of the previous row.
// Problem Description: Given an m x n matrix and a target value, return true if the target is in the matrix or false otherwise. You must write a solution in O(log(m * n)) time complexity.
// Time Complexity: O(log(m * n)) where m is the number of rows and n is the number of columns
// Space Complexity: O(1)
// Difficulty Level: Medium

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = (rows * cols) - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            int r = mid / cols;
            int c = mid % cols;

            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};
