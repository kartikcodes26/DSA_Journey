class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        
        vector<int> ps(arr.size());
        ps[0] = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            ps[i] = ps[i - 1] + arr[i];
        }

        return ps;
    }
};
