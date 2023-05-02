class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) flag = !flag;
        }
        return (flag?1:-1);
    }
};