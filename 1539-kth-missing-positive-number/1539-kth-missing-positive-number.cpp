class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // upper bound using binary search
        // total missing elements at i_th index is
        // arr[i] - (i + 1)
        // we will apply binary search on this
        // ans = arr[i] + k - (arr[i] - (i + 1))
        // ans = k + (i + 1)
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s)/2;
        while(s <= e){
            if(arr[mid] - (mid + 1) < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
        return k + s;
    }
};