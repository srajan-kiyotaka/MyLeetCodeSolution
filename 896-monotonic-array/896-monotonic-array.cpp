class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 3) return true;
        int i = 0;
        
        while(i < nums.size() - 1 && nums[i] == nums[i+1]){i++;}
        
        // cout << i << endl;
        
        if(i >= nums.size()) return true;
        
        // cout << i << endl;
        
        if(i == 0 && nums[0] > nums[1]){
            i++;
            // cout << i << endl;
            for(; i < nums.size(); i++){
                // cout << i << endl;
                if(nums[i] > nums[i - 1]) return false;
            }
        }
        else if(i == 0 && nums[0] < nums[1]){
            i++;
            // cout << i << endl;
            for(; i < nums.size(); i++){
                // cout << i << endl;
                if(nums[i] < nums[i - 1]) return false;
            }
        }
        else if(i < nums.size() - 1 && nums[i] > nums[i + 1]){
            i++;
            // cout << i << endl;
            for(; i < nums.size(); i++){
                // cout << i << endl;
                if(nums[i] > nums[i - 1]) return false;
            }
        }
        else if(i < nums.size() - 1 && nums[i] < nums[i + 1]){
            i++;
            // cout << i << endl;
            for(; i < nums.size(); i++){
                // cout << i << endl;
                if(nums[i] < nums[i - 1]) return false;
            }
        }
        
        return true; 
    }
};