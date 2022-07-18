class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = (nums[i] < 0) ? -1 * nums[i] : nums[i];
            temp--;
            if(nums[temp] < 0){
                ans.push_back(temp + 1);
            }
            else{
                nums[temp] = -nums[temp];
            }
        }
        return ans;
    }
};