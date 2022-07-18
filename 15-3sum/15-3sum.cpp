class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp(3);
        int k, j, size, target;
        size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            if(i > 0 && nums[i] != nums[i-1]){
                temp[0] = nums[i];
                j = i + 1; 
                k = size - 1;
                target = -1 * nums[i];
                while(j < k){
                    if(nums[j] + nums[k] == target){
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        ans.push_back(temp);
                        j++;
                        while(nums[j] == nums[j-1] && j < k){j++;}
                    }
                    else if(nums[j] + nums[k] < target){
                        j++;
                    }
                    else k--;
                }
            }
            else if(i == 0){
                temp[0] = nums[i];
                j = i + 1; 
                k = size - 1;
                target = -1 * nums[i];
                while(j < k){
                    if(nums[j] + nums[k] == target){
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        ans.push_back(temp);
                        j++;
                        while(nums[j] == nums[j-1] && j < k){j++;}
                    }
                    else if(nums[j] + nums[k] < target){
                        j++;
                    }
                    else k--;
                }
            }
        }
        
        return ans;
    }
};