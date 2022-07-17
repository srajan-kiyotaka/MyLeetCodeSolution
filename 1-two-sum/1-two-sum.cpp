class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table ;
        vector<int> a(2);
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(table.find(nums[i]) == table.end()){
                table[nums[i]] = i;
            }
            if(table.find(target - nums[i]) != table.end() && i != table[target - nums[i]]){
                a[0] = i;
                a[1] = table[(target - nums[i])];
                return a;
            }
        }
        
        return a;
        
    }
};