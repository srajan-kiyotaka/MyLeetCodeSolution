class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        if(nums.size() == 1){
            if(nums[0] % k == 0) return 1;
            else return 0;
        }
        if(nums.size() == 0) return 0;
        
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0, sum = 0;
        int r = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            r = sum % k;
            if(r < 0) r += k;
            if(map.find(r) == map.end()){
                map[r] = 1;
            }
            else{
                ans += map[r];
                map[r]++;
            }
        }
        
        return ans;
        
    }
};