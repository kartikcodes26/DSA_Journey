// Leetcode problem no: 860
// Link : https://leetcode.com/problems/lemonade-change/
// difficulty : Easy
// Pattern : Greedy
// TC : O(n) where n is the number of customers
// SC : O(1) as we are not using any extra space


class Solution {
public:
    bool lemonadeChange(vector<int>& cash) {
        bool given = false;
        vector<int> bills = {20, 10, 5};
        vector<int> count = {0, 0, 0};

        for(int i = 0; i < cash.size(); i++)
        {
            given = false;
            int amount = cash[i];

            if(amount == 20) count[0]++;
            if(amount == 10) count[1]++;
            if(amount == 5) count[2]++;

            int toGive = amount - 5;
            if(toGive == 0) continue;
            for(int j = 0; j < 3;)
            {
                if(bills[j] < toGive && count[j] != 0)
                {
                    toGive -= bills[j];
                    count[j]--;
                    if(count[j] != 0) continue;
                }
                else if(bills[j] == toGive && count[j] != 0)
                {
                    given = true;
                    count[j]--;
                    break;
                }
                j++;
            }
            if(!given) return false;
        }

        return true;
    }
};
