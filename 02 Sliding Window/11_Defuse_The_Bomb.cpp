// Leetcode problem 1652. Defuse the Bomb
// link : https://leetcode.com/problems/defuse-the-bomb/
// TC : O(n) where n is the size of the array
// SC : O(n) since we are using extra space for the result array
// Difficulty : Easy (personally medium)
// pattern : Sliding Window

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        long long int sum = 0;

        if(k == 0)
        {
            return res;
        }
        for(int i = 0; i < n; i++)
        {
            if(k > 0)
            {
                for(int j = i + 1; j <= i + k; j++)
                {
                    sum += code[j % n];
                }
                res[i] = sum;
                sum = 0;
            }
            else
            {
                // didnt understand
                for(int j = i - 1; j >= i - abs(k); j--)
                {
                    sum += code[(j + n) % n];
                }
                res[i] = sum;
                sum = 0;
            }
        }
        return res;
    }
};
