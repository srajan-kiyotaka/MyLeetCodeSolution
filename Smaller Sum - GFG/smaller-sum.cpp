//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
     vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> a(n+1,0);
        vector<long long> ans(n,0);
        vector<long long> val(n,0);
        for(int i=0;i<n;i++)
        val[i]=arr[i];
        a[0]=0;
        long sum=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            a[i+1]=sum;
        }
        for(int i=0;i<n;i++)
        {
            int x=lower_bound(arr.begin(),arr.end(),val[i])-arr.begin();
            ans[i]=a[x];
        }
        return ans;
        // Code here
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
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends