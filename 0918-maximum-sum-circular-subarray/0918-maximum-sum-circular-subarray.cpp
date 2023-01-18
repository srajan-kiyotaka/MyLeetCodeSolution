class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> right_max(n);
        right_max[n - 1] = nums[n - 1];
        for (int suffix_sum = nums[n - 1], i = n - 2; i >= 0; --i) {
            suffix_sum += nums[i];
            right_max[i] = max(right_max[i + 1], suffix_sum);
        }
        int max_sum = nums[0];
        int special_sum = nums[0];
        for (int i = 0, suffix_sum = 0, curMax = 0; i < n; ++i) {
            curMax = max(curMax, 0) + nums[i];
            // This is Kadane's algorithm.
            max_sum = max(max_sum, curMax);
            suffix_sum += nums[i];
            if (i + 1 < n) {
                special_sum = max(special_sum, suffix_sum + right_max[i + 1]);
            }
        }
        return max(max_sum, special_sum);
    }
};