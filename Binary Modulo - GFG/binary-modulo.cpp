//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int n = s.length();
            int ans = 0;
            int d = 1;
            for(int i = n - 1; i >= 0; i--){
                if(s[i] == '1'){
                    ans += d;
                    ans = ans % m;
                }
                d *= 2;
                d = d % m;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends