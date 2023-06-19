//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // DP: Bottom Up Approach: Tabulation.
        int maxi = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(mat[i][j] == 1){
                    int ans = INT_MAX;
                    // move right
                    if(j + 1 < m){
                        ans = min(ans, mat[i][j+1]);
                    }
                    else ans = 0;
                    // move down
                    if(i + 1 < n){
                        ans = min(ans, mat[i+1][j]);
                    }
                    else ans = 0;
                    // move diagonal
                    if(i + 1 < n && j + 1 < m){
                        ans = min(ans, mat[i+1][j+1]);
                    }
                    else ans = 0;
                    ans++;
                    maxi = max(ans, maxi);
                    mat[i][j] = ans;
                } 
            }
        }
        
        return maxi;
    }
};


/*

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // DP: Bottom Up Approach: Space Optimization 2.
        int maxi = 0;
        vector<int> prev(n + 1, 0);
        for(int j = m - 1; j >= 0; j--){
            vector<int> curr(n + 1, 0);
            for(int i = n - 1; i >= 0; i--){
                if(mat[i][j] == 1){
                    // move right
                    int ans = min(ans, prev[i]);
                    // move down
                    ans = min(ans, curr[i+1]);
                    // move diagonal
                    ans = min(ans, prev[i+1]);
                    ans++;
                    maxi = max(ans, maxi);
                    curr[i] = ans;
                } 
            }
            prev = curr;
        }
        return maxi;
    }
};

*/


/*

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // DP: Bottom Up Approach: Space Optimization 1.
        int maxi = 0;
        vector<int> prev(m + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            vector<int> curr(m + 1, 0);
            for(int j = m - 1; j >= 0; j--){
                if(mat[i][j] == 1){
                    // move right
                    int ans = min(ans, curr[j+1]);
                    // move down
                    ans = min(ans, prev[j]);
                    // move diagonal
                    ans = min(ans, prev[j+1]);
                    ans++;
                    maxi = max(ans, maxi);
                    curr[j] = ans;
                } 
            }
            prev = curr;
        }
        return maxi;
    }
};

*/


/*

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // DP: Bottom Up Approach: Tabulation.
        int maxi = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(mat[i][j] == 1){
                    // move right
                    int ans = min(ans, dp[i][j+1]);
                    // move down
                    ans = min(ans, dp[i+1][j]);
                    // move diagonal
                    ans = min(ans, dp[i+1][j+1]);
                    ans++;
                    maxi = max(ans, maxi);
                    dp[i][j] = ans;
                } 
            }
        }
        
        return maxi;
    }
};

*/


/*

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

*/


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