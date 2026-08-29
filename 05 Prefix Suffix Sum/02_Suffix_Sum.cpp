class Solution {
  public:
    vector<int> suffSum(vector<int> &arr) {
        
        vector<int> ss(arr.size());
        ss[arr.size() - 1] = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--)
        {
            ss[i] = ss[i + 1] + arr[i];
        }

        return ss;
    }
};
