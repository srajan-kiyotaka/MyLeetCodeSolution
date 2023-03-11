class Solution {
public:
    bool check(vector<int>& nums) {
        // Chek for eack rotation possible.
        // Time complexity = O(n^2)
        // Brute Force Solution.
        // for(int r = 0; r < nums.size(); r++){
        //     bool flag = true;
        //     for(int i = 0; i < nums.size() - 1; i++){
        //         if(nums[(i + r) % nums.size()] <= nums[(i + 1 + r) % nums.size()]){
        //             continue;
        //         }
        //         else{
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag) return true;
        // }
        // return false;
        /*
        Optimized solution:
        case 1. 1,2,3,4,5,6 -> sorted and rotated.
                [         ] -> 1 pair of all sorted.
                            -> 1 Gaps (6 -> 1) (since it is rotated).
        case 2. 3,4,5,6,1,2 -> sorted and rotated. 
                [     ] [ ] -> 2 pair of all sorted. 
                            -> 1 Gaps.
        */
        int gaps = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]){
                gaps++;
            }
        }
        if(nums[nums.size() - 1] > nums[0]) gaps++;
        if(gaps <= 1) return true;
        return false;
    }
};