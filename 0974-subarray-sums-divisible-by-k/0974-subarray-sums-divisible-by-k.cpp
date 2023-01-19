class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        for(int sum = 0, i = 0; i < nums.size(); i++){
            sum += nums[i];
            int r = sum % k;
            r = (r < 0)?(r + k):r;
            if(hashMap.find(r) != hashMap.end()){
                ans += hashMap[r];
                hashMap[r]++;
            }
            else{
                hashMap[r] = 1;
            }
        }
        return ans;
    }
};