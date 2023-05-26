//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define mod 1000000007
class Solution{
    public:
    int nways(int l, double x, int p,vector<vector<int>>&dp){
        
        if(p==0 && l!= 0) return 0;
        if(l == 0) return 1;
        if(l<0) return 0;
        int take = 0; int nottake = 0;
        if(dp[l][p] != -1)return dp[l][p];
        if(pow(p,x) <= l){
            take = nways(l-pow(p,x), x, p-1,dp);
            nottake = nways(l,x,p-1,dp);
            return dp[l][p] = (take+nottake)%mod;
        }
        else{
            nottake = nways(l,x,p-1,dp);
            return dp[l][p] = nottake%mod;
        }
    }
    int numOfWays(int n, int x)
    {
        // here 'p' is the number from where should we start calculating like p^x + (p-1)^x.....
        // like for n = 100 and x = 2, p should be 10 which is the maximum number we can use in
        // summation of natural numbers raised to power 'x' to form 'n'.
        int p = pow((double)n,1/(double)x);
         vector<vector<int>>dp(n+1,vector<int>(p+1,-1));
        return nways(n,x,p,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends