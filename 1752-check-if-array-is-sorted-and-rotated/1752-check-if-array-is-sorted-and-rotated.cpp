class Solution {
public:
    bool check(vector<int>& nums) {
        // Chek for eack rotation possible.
        // Time complexity = O(n^2)
        for(int r = 0; r < nums.size(); r++){
            bool flag = true;
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[(i + r) % nums.size()] <= nums[(i + 1 + r) % nums.size()]){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};