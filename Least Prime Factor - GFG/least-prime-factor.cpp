//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++)
        {
            int f=0;
            if(i == 1 || i == 2)
            {
                ans[i]=i;
            }
            else if(i%2==0)
                ans[i]=2;
            else 
            {
                for(int j=3;j<=(int)sqrt(n);j+=2)
                {
                    
                    if(i%j==0)
                    {
                        f=1;
                        ans[i]=j;
                        break;
                    }
                }
                if(!f)
                    ans[i]=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends