//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int i = 0, j = 0, k = 0;
        int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
        while(k<s.size()){
            switch(s[k++]){
                case 'L': { j--; break; }
                case 'R': { j++; break; }
                case 'D': { i++; break; }
                case 'U': { i--; break; }
            }
           xmax = max(xmax, j);
           xmin = min(xmin,j);
           ymax = max(ymax, i);
           ymin = min(ymin,i);
        }
        if(ymax - ymin < n && xmax - xmin < m) 
          return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends