class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row_s = 0;
        int row_e = matrix.size() - 1;
        int col_s = 0;
        int col_e = matrix[0].size() - 1;
        while(matrix.size()*matrix[0].size() > ans.size()){
            for(int i = col_s; i <= col_e && matrix.size()*matrix[0].size() > ans.size(); i++){
                ans.push_back(matrix[row_s][i]);
            }
            row_s++;
            for(int i = row_s; i <= row_e && matrix.size()*matrix[0].size() > ans.size(); i++){
                ans.push_back(matrix[i][col_e]);
            }
            col_e--;
            for(int i = col_e; i >= col_s && matrix.size()*matrix[0].size() > ans.size(); i--){
                ans.push_back(matrix[row_e][i]);
            }
            row_e--;
            for(int i = row_e; i >= row_s && matrix.size()*matrix[0].size() > ans.size(); i--){
                ans.push_back(matrix[i][col_s]);
            }
            col_s++;
        }
        return ans;
    }
};