// Leetcode 151. Reverse Words in a String
// Link : https://leetcode.com/problems/reverse-words-in-a-string/
// TC : O(n) where n is the length of the string
// SC : O(n) where n is the length of the string
// Difficulty : Medium
// Pattern : String

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = s.size() - 1;
        string word;
        while(s[i] == ' ')
        {
            i--;
            if(i < 0) return "";
        }
        while(i >= 0)
        {
            while(s[i] != ' ')
            {
                word.push_back(s[i]);
                i--;
                if(i < 0) break;
            }
            if(!word.empty())
            {
                reverse(word.begin(), word.end());
                for(auto ele : word) res.push_back(ele);
                res.push_back(' ');
                word.clear();
            }
            i--;
        }
        res.erase(res.size() - 1, 1);
        return res;
    }
};
