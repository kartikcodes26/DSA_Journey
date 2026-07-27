// leetcode 682. Baseball Game
// You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.
// time complexity: O(n)
// space complexity: O(n)
// difficulty: Easy

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int prevS;
        int j = -1;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "D")
            {
                scores.push_back(scores[j] * 2);
                j++;
            }
            else if(operations[i] == "C")
            {
                scores.erase(scores.begin() + j);
                j--;
            }
            else if(operations[i] == "+")
            {
                scores.push_back(scores[j] + scores[j - 1]);
                j++;
            }
            else
            {
                scores.push_back(stoi(operations[i]));
                j++;
            }

        }

        int res = 0;

        for(auto ele : scores)
        {
            res += ele;
        }

        return res;
    }
};
