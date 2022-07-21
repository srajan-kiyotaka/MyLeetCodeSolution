class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        if(nums.size() == 2){
            if(nums[0] == target) return 0;
            else if(nums[1] == target) return 1;
            return -1;
        }
        int i = 0;
        int j = nums.size() - 1;
        int middle = 0;
        while(i <= j){
            middle = (i + j)/2;
            if(nums[middle] == target) return middle;

            else if(nums[middle] >= nums[i]){
                if(nums[i] <= target && nums[middle] >= target){
                    j = middle - 1;
                }
                else{
                    i = middle + 1;
                }
            }
            else{
                if(nums[j] >= target && nums[middle] <= target){
                    i = middle + 1;
                }
                else{
                    j = middle - 1;
                }
            }
        }
        return -1;
    }
};