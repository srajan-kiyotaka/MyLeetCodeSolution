//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isPower5(string &s,int i,int j)
    {
        if (s[i] == '0') return false;  
        long long num = 0;
        for (int k = i; k <= j; k++)num = num * 2 + (s[k] - '0');
        while (num > 1) 
        {
            if (num % 5 != 0) return false;
            num /= 5;
        }
        return true;
    }
    int mcm(string& s,int i,int j,vector<vector<int>>&dp)
    {
        if(isPower5(s,i,j))return 1;
        
        if(dp[i][j]!=-2)return dp[i][j];
        
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int left=mcm(s,i,k,dp);
            if(left==-1)continue;
            int right=mcm(s,k+1,j,dp);
            if(right==-1)continue;
            mini=min(mini,left+right);
        }
        
        return dp[i][j]=(mini==INT_MAX?-1:mini);
    }
    int cuts(string s){
        if(isPower5(s,0,s.size()-1))return 1;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-2));
        return mcm(s,0,s.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends