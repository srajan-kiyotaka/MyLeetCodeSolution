class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> map;
        for(int i = 0; i < size; i++){
            if(map.find(nums[i]) != map.end()){
                map[nums[i]]++;
                if(map[nums[i]] > (size / 2)) return nums[i];
            }
            else{
                map[nums[i]] = 1;
            }
        }
        return nums[size - 1];
    }
};