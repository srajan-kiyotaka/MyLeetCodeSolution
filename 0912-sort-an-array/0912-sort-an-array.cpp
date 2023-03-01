class Solution {
public:
   void merge(int low, int mid, int high, vector<int> &nums) {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while (l <= mid) 
            sorted[k++] = nums[l++];
        while (r <= high) 
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(start, mid, end, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    int partision(vector<int>& vec, int low, int high){
        int piviot = vec[low];
        int i = low;
        int j = high;
        while(i < j){
            // cout << i << " " << j << endl;
            while(i <= j && vec[i] <= piviot){i++;}
            // cout << i << " " << j << endl;
            while(i <= j && vec[j] > piviot){j--;}
            // cout << i << " " << j << endl;
            if(i < j){swap(vec[i], vec[j]);}
        }
        swap(vec[low], vec[j]);
        return j;
    }

    void quickSort(vector<int>& vec, int l, int h){
        // cout << "in" << endl;
        int j;
        if(l < h){
            j = partision(vec, l, h);
            // cout << j << endl;
            quickSort(vec, l, j - 1);
            quickSort(vec, j + 1, h);
        }
    }

    // vector<int> sortArray(vector<int>& nums) {
    //     // quickSort(nums, 0, nums.size() - 1);
    //     rMergeSort(nums, 0, nums.size() - 1);
    //     return nums;
    // }
};