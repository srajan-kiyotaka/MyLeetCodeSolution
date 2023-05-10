class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row1 = 0;
        int row2 = n-1;
        int col1 = 0;
        int col2 = n-1;
        int track = 0;
        int number = 1;
        while(row1<=row2 && col1<=col2){
            if(track % 4 == 0){
                for(int i = col1; i <= col2; i++){
                    matrix[row1][i] = number;
                    number++;
                }
                row1++;
                track++;
            }
            else if(track % 4 == 1){
                for(int i = row1; i <= row2; i++){
                    matrix[i][col2] = number;
                    number++;
                }
                track++;
                col2--;
            }
            else if(track % 4 == 2){
                for(int i = col2; i >= col1; i--){
                    matrix[row2][i] = number;
                    number++;
                }
                row2--;
                track++;
            }
            else{
                for(int i = row2; i >= row1; i--){
                    matrix[i][col1] = number;
                    number++;
                }
                track++;
                col1++;
            }
        }
        return matrix;
    }
};