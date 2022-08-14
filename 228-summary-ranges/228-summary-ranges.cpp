class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        long long pre = 0;
        bool flag = false;
        long long i = 0, j = 1;
        while(i < nums.size() && j < nums.size()){
            long long k = 1;
            while(j < nums.size() && nums[j] == k + nums[i]){k++;j++;}
            if(i != j-1){ 
            string temp = to_string(nums[i]) + "->" + to_string(nums[j-1]);
            ans.push_back(temp);
            }
            else{
                ans.push_back(to_string(nums[i]));
            }
            i = j;
            j++;
        }
        if(i < nums.size()){
            ans.push_back(to_string(nums[i]));
        }
        return ans;
    }
};