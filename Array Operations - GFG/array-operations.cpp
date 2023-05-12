//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int ans = 0;
        bool flag = false;
        // int zerocount = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(arr[0] != 0) flag = true;
                // else zerocount++;
                continue;
            }
            if(arr[i] == 0 && flag){
                // zerocount++;
                ans++;
                flag = false;
            }
            if(arr[i] != 0) flag = true;
        }
        if(flag == true) ans++;
        // return (zerocount != 0)?(ans):(0);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends