class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            while(i < nums.size() && nums[i] % 2 == 0){i++;}
            if(i >= nums.size()) return nums;
            while(j >= 0 && nums[j] % 2 == 1){j--;}
            if(j <= i) return nums;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};