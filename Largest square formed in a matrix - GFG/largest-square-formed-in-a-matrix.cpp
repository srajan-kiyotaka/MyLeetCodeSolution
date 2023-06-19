//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int allSquares(int n, int m, vector<vector<int>>& mat, int row, int col, int &maxi, 
                   vector<vector<int>> &dp){
        // Base Case
        if(row >= n || col >= m) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        // Move Right
        int right = allSquares(n, m, mat, row, col + 1, maxi, dp);
        // Move Down
        int down = allSquares(n, m, mat, row + 1, col, maxi, dp);
        // Move Diagonal
        int diag = allSquares(n, m, mat, row + 1, col + 1, maxi, dp);
        // Check
        if(mat[row][col] == 1){
            int ans = 1 + min(right, min(down, diag));
            maxi = max(maxi, ans);
            return dp[row][col] = ans;
        }
        else return dp[row][col] = 0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // DP: Top Down Approach: Recursion + Memoization.
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        allSquares(n, m, mat, 0, 0, maxi, dp);
        return maxi;
    }
};

/*

class Solution{
private:
    int allSquares(int n, int m, vector<vector<int>>& mat, int row, int col, int &maxi){
        // Base Case
        if(row >= n || col >= m) return 0;
        // Move Right
        int right = allSquares(n, m, mat, row, col + 1, maxi);
        // Move Down
        int down = allSquares(n, m, mat, row + 1, col, maxi);
        // Move Diagonal
        int diag = allSquares(n, m, mat, row + 1, col + 1, maxi);
        // Check
        if(mat[row][col] == 1){
            int ans = 1 + min(right, min(down, diag));
            maxi = max(maxi, ans);
            return ans;
        }
        else return 0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // Recursive Solution.
        int maxi = 0;
        allSquares(n, m, mat, 0, 0, maxi);
        return maxi;
    }
};

*/

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends