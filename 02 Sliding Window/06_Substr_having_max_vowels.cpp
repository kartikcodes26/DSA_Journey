// Leetcode 1456. Maximum Number of Vowels in a Substring of Given Length
// Time Complexity: O(n)
// Space Complexity: O(1)
// Sliding Window Approach fixed

class Solution {
public:
    long long int countvowels(const int& low, const int& high,
                              const string& s) {
        long long int count = 0;
        for (int i = low; i <= high; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }
        return count;
    }

    bool isvowel(char s) {

        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
            return true;
        }

        return false;
    }

    long long int maxVowels(const string& s, const int& k) {
        long long int low = 0;
        long long int high = k - 1;

        long long int res = 0;
        long long int count = countvowels(low, high, s);
        
        while (high < s.size()) {
            res = max(res, count);

            low++;
            high++;

            if (isvowel(s[high])) {
                count++;
            }
            if (isvowel(s[low - 1])) {
                count--;
            }
        }

        return res;
    }
};
