class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Insted of going from front to back
        // we will go from back to front.
        // travel the arrays from the back.
        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];
            }
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};