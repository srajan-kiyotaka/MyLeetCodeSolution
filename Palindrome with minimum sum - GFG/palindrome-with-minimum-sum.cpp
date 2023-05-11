//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string str) {
        // code here
        int n=str.size();
        int i=0,j=n-1;
        while(i<j){
            if(((str[i]>='a' and str[i]<='z') and str[j]=='?')){
                str[j]=str[i];
            }else if(((str[j]>='a' and str[j]<='z') and str[i]=='?')){
                str[i]=str[j];
            }else if(((str[i]>='a' and str[i]<='z') and (str[j]>='a' and str[j]<='z')) and str[i]!=str[j]){
                return -1;
            }
            i++;
            j--;
        }
        
        int startInd=-1,endInd=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(str[i]>='a' and str[i]<='z'){
                if(startInd==-1){
                    startInd=i;
                }else{
                    endInd=i;
                }
            }
            
            if(startInd!=-1 and endInd!=-1){
                ans+=abs((str[startInd]-'a')-(str[endInd]-'a'));
                startInd=endInd;
                endInd=-1;
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
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends