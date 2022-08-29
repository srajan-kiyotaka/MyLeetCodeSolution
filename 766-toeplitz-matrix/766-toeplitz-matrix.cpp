class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < m; i++){
            int a = 0;
            int j = i;
            int temp = matrix[a][j];
            while(a < n && j < m){
                if(temp != matrix[a][j]){
                    return false;
                }
                a++;
                j++;
            }
        }
        for(int i = 0; i < n; i++){
            int a = i;
            int j = 0;
            int temp = matrix[a][j];
            while(a < n && j < m){
                if(temp != matrix[a][j]){
                    return false;
                }
                a++;
                j++;
            }
        }
        return true;
    }
};