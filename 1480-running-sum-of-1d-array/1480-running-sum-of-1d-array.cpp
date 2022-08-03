class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        if(nums.size() == 0) return ans;
        ans[0] = nums[0];
        for(int i= 1; i < nums.size(); i++) ans[i] = ans[i-1] + nums[i];
        return ans;
    }
};