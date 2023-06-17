//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int allSquares(int n, vector<int> &dp){
        // Base Case
        if(n == 0) return 0;
        if(n < 0) return INT_MAX/2;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++){
            ans = min(ans, 1 + allSquares(n - i*i, dp));
        }
        return dp[n] = ans;
        
    }
	public:
	int MinSquares(int n)
	{
	    // DP: Top Down Approach: Recursive + Memoization.
	    vector<int> dp(n+1, INT_MAX/2);
	    dp[0] = 0;
	    dp[1] = 1;
	    for(int i = 2; i <= n; i++){
	        for(int j = 1; j <= sqrt(i); j++){
	            if(i - j*j >= 0){
	               // cout << j << endl;
	                dp[i] = min(dp[i], 1 + dp[i - j*j]);
	            }
	           // else break;
	        }
	       // cout << " i = " << i << ", dp[i] = " << dp[i] << endl;
	    }
	    return dp[n];
	}
};






/*

class Solution{
    private:
    int allSquares(int n, vector<int> &dp){
        // Base Case
        if(n == 0) return 0;
        if(n < 0) return INT_MAX/2;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++){
            ans = min(ans, 1 + allSquares(n - i*i, dp));
        }
        return dp[n] = ans;
        
    }
	public:
	int MinSquares(int n)
	{
	    // DP: Top Down Approach: Recursive + Memoization.
	    vector<int> dp(n+1, -1);
	    return allSquares(n, dp);
	}
};

*/


/*

class Solution{
    private:
    int allSquares(int n){
        // Base Case
        if(n == 0) return 0;
        if(n < 0) return INT_MAX/2;
        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++){
            ans = min(ans, 1 + allSquares(n - i*i));
        }
        return ans;
        
    }
	public:
	int MinSquares(int n)
	{
	    // Recursive Approach.
	    return allSquares(n);
	}
};

*/

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends