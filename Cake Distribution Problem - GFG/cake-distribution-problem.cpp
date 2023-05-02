//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool check(int mid,vector<int>& sweetness, int N, int K)
    {
        int cnt = 0;
        int pre = 0;
        for(int i = 0; i<N; i++)
        {
            pre = pre+sweetness[i];
            if(pre >= mid)
            {
                cnt++;
                pre = 0;
            }
        }
        return cnt >= K+1;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int lo = 1e9; int hi = 0; int ans = -1; 
        for(int i = 0; i<N; i++)
        {
            lo = min(lo,sweetness[i]);
            hi = hi+sweetness[i];
        }
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(check(mid,sweetness,N,K))
            {
                ans = mid;
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        return ans;
    // Write your code here.
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends