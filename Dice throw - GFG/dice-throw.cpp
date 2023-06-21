//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        // DP: Bottom Up Approach: Tabulation.
        // Time Complexity: O(M*N)
        // Space Complexity: O(N*X)
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++){
            for(int t = 1; t <= X; t++){
                for(int j = 1; j <= M; j++){
                    if(t >= j)
                        dp[i][t] += dp[i-1][t-j];
                }
            }
        }
        return dp[N][X];
    }
};


/*

class Solution {
  private:
    long long solver(int M, int N, int X, vector<vector<long long>> &dp){
        // Base Case
        if(X < 0) return 0;
        if(N == 0 && X == 0) return 1;
        if(N == 0 && X != 0) return 0;
        if(dp[N][X] != -1) return dp[N][X];
        long long count = 0;
        for(int i = 1; i <= M; i++){
            count += solver(M, N-1, X-i, dp);
        }
        return dp[N][X] = count;
    }  
  public:
    long long noOfWays(int M , int N , int X) {
        // DP: Top Down Approach: Recursion + Memoization.
        // Time Complexity: O(M*N)
        // Space Complexity: O(N*X)
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        return solver(M, N, X, dp);
    }
};

*/


/*

class Solution {
  private:
    long long solver(int M, int N, int X){
        // Base Case
        if(X < 0) return 0;
        if(N == 0 && X == 0) return 1;
        if(N == 0 && X != 0) return 0;
        long long count = 0;
        for(int i = 1; i <= M; i++){
            count += solver(M, N-1, X-i);
        }
        return count;
    }  
  public:
    long long noOfWays(int M , int N , int X) {
        // Recursive Approach.
        // Time Complexity: O(M^N)
        // Space Complexity: O(N)
        return solver(M, N, X);
    }
};

*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends