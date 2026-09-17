// Leetcode 202. Happy Number
// Link : https://leetcode.com/problems/happy-number/
// TC : O(log n) where n is the number of digits in the number
// SC : O(log n) where n is the number of digits in the number
// Difficulty : Easy
// Pattern : Hashing

class Solution {
public:
    bool isHappy(int n) {
        int digit = 0;
        int temp = n;
        unordered_map<int,int> mp;
        int res = 0;
        while(true)
        {
            while(n > 0)
            {
                digit = n % 10;
                res += digit * digit;
                n = n / 10;
            }
            if(res == 1) return true;
            else
            {
                if(mp.find(res) != mp.end()) return false;
                n = res;
                res = 0;
                mp[n] = n;
            }
        }
        return false;
    }

};
