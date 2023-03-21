class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubarray = 0;
        
        // Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        // than the previous one, otherwise, it has 0 zero-filled subarray.
        for (auto num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        
        return ans;
    }
};

// 2 Pointer Approch
/*

long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        while(i < nums.size()){
            while(i < nums.size() && nums[i] != 0){
                i++;
            }
            if(i == nums.size()) break;
            int j = i+1;
            while(j < nums.size() && nums[j] == 0){
                j++;
            }
            int n = j - i;
            ans += (1LL)*((1LL)*n*(n+1))/2;
            i = j + 1;
        }
        return ans;
    }

*/

// Iterative method
/*

long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubarray = 0;
        
        // Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        // than the previous one, otherwise, it has 0 zero-filled subarray.
        for (auto num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        
        return ans;
    }

*/

// Using Hash Map(Couting the different groups of zeros).
/*
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

*/