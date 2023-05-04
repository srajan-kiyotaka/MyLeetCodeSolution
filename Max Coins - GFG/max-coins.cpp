//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
       vector<vector<int>>v;
       for(int i=0;i<n;i++)
       v.push_back({ranges[i][2],ranges[i][0],ranges[i][1]});
       sort(v.begin(),v.end());
       reverse(v.begin(),v.end());
       int sum,maxsum=0;
       for(int i=0;i<n;i++){
         sum=v[i][0];
         if(maxsum>=2*sum) break;
         for(int j=i+1;j<n;j++){
            if(v[j][1]>=v[i][2]||v[i][1]>=v[j][2]){
               sum=sum+v[j][0];
               break;
            }
         }
         maxsum=max(sum,maxsum);
       }
       return maxsum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends