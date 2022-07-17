class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x = 0, y = 0;
        do{
            x = nums[x];
            y = nums[y];
            y = nums[y];
        }while(x != y);
        
        y = 0;
        while(x != y){
            x = nums[x];
            y = nums[y];
        }
        return x; 
    }
};

