class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        if(target < nums[i]) return i;
        if(target > nums[j]) return j + 1;
        int mid = (i + j ) / 2;
        while(i != j){
            mid = (i + j) / 2;
            if(target < nums[mid]){
                if(j == mid) return j - 1 ;
                j = mid;
            }
            else if(target > nums[mid]){
                if(i == mid) return i + 1 ;
                i = mid;
            }
            else{
                return mid;
            }
        }
        return i;
    }
};