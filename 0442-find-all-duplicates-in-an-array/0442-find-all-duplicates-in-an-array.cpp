class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       unordered_map<int, int> hashMap;
       vector<int> ans;
       for(int i = 0; i < nums.size(); i++){
           hashMap[nums[i]]++;
       } 
       for(auto it : hashMap){
           if(it.second == 2){
               ans.push_back(it.first);
           }
       }
       return ans;
    }

    /*
    
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = (nums[i] < 0) ? -1 * nums[i] : nums[i];
            temp--;
            if(nums[temp] < 0){
                ans.push_back(temp + 1);
            }
            else{
                nums[temp] = -nums[temp];
            }
        }
        return ans;
    }
    
    */
};