class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> hash(nums.size(), -1);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i] - 1] = 1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(hash[i] == -1)
                ans.push_back(i + 1);
        }
        return ans;
    }
};