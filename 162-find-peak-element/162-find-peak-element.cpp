class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2){
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        int i = 0;
        int middle;
        int j = nums.size() - 1;
        while(true){
            middle = (i + j)/2;
            if(middle == 0){
                if(nums[middle] > nums[middle + 1]){
                    return middle;
                }
                i++;
            }
            else if(middle == nums.size() - 1){
                if(nums[middle] > nums[middle - 1]){
                    return middle;
                }
                j--;
            }
            else{
                if(nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]){
                    return middle;
                }
                else if(nums[middle] > nums[middle - 1]){
                    i = middle + 1;
                    
                }
                else if(nums[middle] > nums[middle + 1]){
                    j = middle - 1;
                }
                else{
                    i = middle + 1;
                }
            }
        }
        return middle;
    }
};