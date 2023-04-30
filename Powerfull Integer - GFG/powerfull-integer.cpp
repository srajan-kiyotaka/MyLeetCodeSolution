//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, intervals[i][1]);
        }
        // frequency array
        vector<int> arr(maxi+3, 0);

        int ans = -1;
        if(k > n) return -1;
        for(int i = 0; i < n; i++){
                arr[intervals[i][0]] += 1;
                arr[intervals[i][1] + 1] -= 1;
        }
        for(int i = 1; i <= maxi + 2; i++){
            arr[i] = arr[i] + arr[i-1];
            if(arr[i] >= k) ans = i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends