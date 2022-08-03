class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());
        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[i + nums.size()] = ans[i];
        }
        
        return ans;
    }
};