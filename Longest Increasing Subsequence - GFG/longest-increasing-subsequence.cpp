//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // DP with Binary Search.
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty()) ans.push_back(a[i]);
            else{
                if(ans.back() < a[i]) ans.push_back(a[i]);
                else{
                    // Binary Search
                    int s = 0;
                    int e = ans.size() - 1;
                    int mid = s + (e - s)/2;
                    while(s <= e){
                        if(ans[mid] == a[i]) break;
                        else if(ans[mid] > a[i]) e = mid - 1;
                        else s = mid + 1;
                        mid = s + (e - s)/2;
                    }
                    ans[s] = a[i];
                }
            }
        }
        return ans.size();
    }
};

/*

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // DP: Bottom Up Approach: Space Optimization.
       // Time Complexity: O(N*N)
       // Space Complexity: O(N)
       vector<int> prev(n + 1, 0);
       for(int i = n - 1; i >= 0; i--){
           vector<int> curr(n + 1, 0);
           for(int j = i - 1; j >= -1; j--){
                // Exclude
                curr[j+1] = prev[j+1];
                // Include
                if(j == -1 || a[i] > a[j])
                    curr[j+1] = max(curr[j+1], 1 + prev[i+1]);
           }
            prev = curr;
       }
       return prev[0];
    }
};

*/


/*

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // DP: Bottom Up Approach: Tabulation.
       // Time Complexity: O(N*N)
       // Space Complexity: O(N*N)
       vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
       for(int i = n - 1; i >= 0; i--){
           for(int j = i - 1; j >= -1; j--){
                // Exclude
                dp[i][j+1] = dp[i+1][j+1];
                // Include
                if(j == -1 || a[i] > a[j])
                    dp[i][j+1] = max(dp[i][j+1], 1 + dp[i+1][i+1]);
           }
       }
       return dp[0][0];
    }
};

*/


/*

class Solution
{
    private:
    int solver(int n, int a[], int index, int prev, vector<vector<int>> &dp){
        // Base Case
        if(index == n){
            return 0;
        }
        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];
        // Exclude
        int ans = solver(n, a, index + 1, prev, dp);
        // Include
        if(prev == -1 || a[index] > a[prev])
            ans = max(ans, 1 + solver(n, a, index + 1, index, dp));
        return dp[index][prev + 1] = ans;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // DP: Top Down Approach: Recursion + Memoization.
       // Time Complexity: O(N*N)
       // Space Complexity: O(N*N)
       vector<vector<int>> dp(n, vector<int>(n + 1, -1));
       return solver(n, a, 0, -1, dp);
       
    }
};

*/


/*

class Solution
{
    private:
    int solver(int n, int a[], int index, int prev){
        // Base Case
        if(index >= n){
            return 0;
        }
        // Exclude
        int ans = solver(n, a, index + 1, prev);
        // Include
        if(a[index] > prev)
            ans = max(ans, 1 + solver(n, a, index + 1, a[index]));
        return ans;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // Recursive Approach.
       // Time Complexity: O(2^N*N)
       // Space Complexity: O(N)
       return solver(n, a, 0, -1);
       
    }
};

*/


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends