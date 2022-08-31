class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> y(n,0);
        vector<int> x(n,0);
        for(int i = 0; i < n; i++){
            y[i] = nums[n+i];
            x[i] = nums[i];
            // nums[i] = nums[i - n];
        }
        // for(int i = 0; i < 2*n; i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        for(int i = 0, j = 0; j < n ; j++){
            nums[i++] = x[j];
            nums[i++] = y[j];
        }
        return nums;
    }
};