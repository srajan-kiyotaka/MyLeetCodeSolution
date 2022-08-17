class NumArray {
public:
    vector<int> result;
    NumArray(vector<int>& nums) {
        result = nums;
        // copy(nums.begin(), nums.end(), back_inserter(result));
    }
    
    int sumRange(int left, int right) {
        long long sum = 0;
        // cout << result[left] << endl;
        for(int i = left; i <= right; i++){
            sum += result[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */