class Solution {
public:
    vector<vector<int>> result;

    void recurtion(vector<int>& nums, vector<int> array, int pointer){
        if(pointer == nums.size()){
            // check(array)
            if(array.size() >= 2){
                result.push_back(array);
            }
            return;
        }

        recurtion(nums, array, pointer + 1);

        if(array.empty() || array[array.size() - 1] <= nums[pointer]){
            array.push_back(nums[pointer]);
            recurtion(nums, array, pointer + 1);
        }
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        recurtion(nums, temp, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};