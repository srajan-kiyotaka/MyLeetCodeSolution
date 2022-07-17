class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int size = nums.size();
        while(i < (size - 1) && j < size){
            while(nums[i] != 0 && i < size - 1){i++;}
            
            j = i + 1;
            if(j == size) break;
            
            while(nums[j] == 0 && j < size){j++;
                if(j == size) break;
            }
            if(i < size && j < size){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};