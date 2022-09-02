class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> hash_map(101, 0);
        for(int i = 0; i < nums.size(); i++){
            hash_map[nums[i]]++;
        }
        int sum = 0;
        for(int i = 0; i < 101; i++){
            int temp = hash_map[i];
            hash_map[i] = sum;
            sum += temp; 
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = hash_map[nums[i]];
        }
        return nums;
    }
};