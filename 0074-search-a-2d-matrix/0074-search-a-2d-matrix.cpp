class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search
        // start = 0, end = n*m - 1
        // mid = (start + end)/2
        // row = mid / m
        // col = mid % m
        int s = 0;
        int end = matrix.size()*matrix[0].size() - 1;
        int mid = s + (end - s)/2;
        while(s <= end){
            int i = mid / matrix[0].size();
            int j = mid % matrix[0].size();
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) end = mid - 1;
            else s = mid + 1;
            mid = s + (end - s)/2;
        }
        return false;
    }
};