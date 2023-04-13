//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    typedef pair<long long, long long> pll;
    pll minmax(long long pre[],int l , int r){
        int low=l, high=r-1;
        long long minsum=0;
        long long maxsum= pre[r]-pre[l-1];
        while(low<=high){
            int mid= low+(high-low)/2;
            long long lsum= pre[mid]- pre[l-1];
            long long rsum= pre[r]-pre[mid];
            
            if(abs(rsum-lsum)< (maxsum-minsum)){
                minsum=min(lsum,rsum);
                maxsum=max(lsum,rsum);
            }
            if(lsum<rsum)
            low=mid+1;
            else
            high=mid-1;
        }
        
        return {minsum,maxsum};
    }
    
    long long minDifference(int N, vector<int> &A) {
        long long presum[N+1];
        presum[0]=0;
        for(int i=1;i<=N;i++)
        presum[i]=A[i-1]+presum[i-1];
        
        long long ans= presum[N];
        
        for(int i=1;i<N-2;i++){
            pll mml= minmax(presum,1,i+1);
            pll mmr= minmax(presum,i+2,N);
            ans=min(ans, max(mml.second,mmr.second) - min(mml.first,mmr.first));
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends