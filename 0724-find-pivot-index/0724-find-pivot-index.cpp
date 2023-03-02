class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int size = nums.size();
        for(int i = 1; i < size; i++){
            nums[i] += nums[i - 1];
        }
        if(nums[size - 1] - nums[0] == 0) return 0;
        // if(nums[size - 2] == 0) return size - 1;
        for(int i = 1; i < size; i++){
            if(nums[i - 1] == nums[size - 1] - nums[i]) return i;
        }
        return -1;
    }
};