class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Using Maths
        // Time Complexity : O(N^2)
        // Space Complexity : O(1)
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
    
/*
// Extra Space Solution!
    vector<vector<int>> temp = matrix;
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = temp[n - j - 1][i];
        }
    }
    temp.erase(temp.begin(), temp.end());

*/