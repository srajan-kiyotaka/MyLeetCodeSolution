class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0, middle = nums[n/2];
        for(int i = 0; i < n; i++){
            ans += (nums[i] - middle) > 0 ? (nums[i] - middle) : (- nums[i] + middle);
        }
        
        return ans;
    }
};