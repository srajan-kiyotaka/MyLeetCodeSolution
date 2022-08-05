class Solution {
public:
    unordered_map<int, int> map;
    
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)return 1;
        if(target < 0) return 0;
        if(map.find(target) != map.end()) return map[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i])
                ans += combinationSum4(nums, target - nums[i]);
        }
        map[target] = ans;
        return ans;
    }
};