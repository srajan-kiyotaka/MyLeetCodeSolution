class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // Moving Average
        // if maximum is at 0th index
        int index = max_element(nums.begin(), nums.end()) - nums.begin();
        if(index == 0) return nums[0];
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, (sum + i)/(i + 1));
        }
        return ans;
    }
};

/*
    Binar Search
    Time Complexity: O(NlogN)

    bool solutionExits(vector<int>& nums, long long ans){
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > (1ll)*(ans*(i+1))) return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        long long e = *max_element(nums.begin(), nums.end());
        long long s = 0;
        long long mid = s + (e - s)/2;
        long long ans = 0;
        while(s <= e){
            if(solutionExits(nums, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s)/2;
        }        
        return ans;
    }

*/


/*

// if maximum is at 0th index
        int index = max_element(nums.begin(), nums.end()) - nums.begin();
        if(index == 0) return nums[0];
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, (sum + i)/(i + 1));
        }
        return ans;

*/