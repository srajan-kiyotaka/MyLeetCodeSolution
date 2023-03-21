class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> hash;
        int len = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                len++;
            }
            else{
                hash[len]++;
                len = 0;
            }
        }
        if(len > 0){
            hash[len]++;
            len = 0;
        }
        for(auto it : hash){
            if(it.first != 0){
                ans += (1LL)*it.second*(1LL)*((1LL)*it.first*(it.first+1)/2);
            }
        }
        return ans;
    }
};