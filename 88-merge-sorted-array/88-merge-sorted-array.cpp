class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> v(m + n);
        int i = 0, j = 0, k = 0;
        if(m == 0){
            return ;
        }
        
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                v[k++] = nums1[i++];
            }
            else{
                v[k++] = nums2[j++];
            }
        }
        for(; i < n; i++){
            v[k++] = nums1[i];
        }
        for(; j < m; j++){
            v[k++] = nums2[j];
        }
        for(i = 0; i < m + n; i++){
            nums1[i] = v[i];
        }
    }
};