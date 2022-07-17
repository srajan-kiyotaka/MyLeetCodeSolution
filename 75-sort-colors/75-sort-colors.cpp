class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        vector<int> a(3);
        for(int i = 0; i < size; i++){
            a[nums[i]]++;
        }
        int i = 0;
        for(; i < a[0]; i++){
            nums[i] = 0;
        }
        for(i = 0;i < a[1]; i++){
            nums[i + a[0]] = 1;
        }
        for(i = 0;i < a[2]; i++){
            nums[i + a[0] + a[1]] = 2;
        }
    }
};