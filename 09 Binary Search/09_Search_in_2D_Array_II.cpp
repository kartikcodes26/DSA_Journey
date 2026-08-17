// LeetCode problem no: 240
// Problem Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    // Integers in each row are sorted in ascending from left to right.
    // Integers in each column are sorted in ascending from top to bottom.
// Problem Description: Given an m x n matrix and a target value, return true if the target is in the matrix or false otherwise. You must write a solution in O(m + n) time complexity.
// Time Complexity: O(m + n) where m is the number of rows and n is the number of columns
// Space Complexity: O(1)
// Difficulty Level: Medium
// Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 300
    // -10^9 <= matrix[i][j] <= 10^9
    // All the integers in each row are sorted in ascending order.
    // All the integers in each column are sorted in ascending order.
    // -10^9 <= target <= 10^9


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = rows - 1; // i denotes row
        int j = 0; // j denotes column

        while(i >= 0 && j <= cols - 1)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
};
