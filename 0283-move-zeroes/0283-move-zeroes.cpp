class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        Find a zero then a non-zero and swap them.
        */
        // int i = 0;
        // int j = i + 1;
        // int n = nums.size();
        // while(i < n && j < n){
        //     while(i < n && nums[i] != 0){i++;}
        //     j = i + 1;
        //     while(j < n && nums[j] == 0){j++;}
        //     if(i < n && j < n){
        //         swap(nums[i], nums[j]);
        //     }
        // }
        
        /*
        Bring all the non-zero elements to the front.
        */
        int front = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[front], nums[i]);
                front++;
            }
        }

    }
};