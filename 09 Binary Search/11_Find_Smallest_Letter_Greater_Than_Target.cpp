// Leetcode 744
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        char res;
        bool found = false;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(letters[mid] > target)
            {
                found = true;
                res = letters[mid];
                high = mid - 1;
            }
            else // Equal to nahi chalega, agar mila toh aur bada karo phir smallest dhundo
            {
                low = mid + 1;
            }
        }

        if(found)
        {
            return res;
        }
        else
        {
            return letters[0];
        }
    }
};
