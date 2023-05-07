//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        string s;
        s.push_back(str[0]);
        for(int i = 1; i < str.length(); i++){
            if(i > 1 && str[i] <= s[i-1]){
                s.push_back(str[i]);
            }
            else if(str[i] < s[i-1]){
                s.push_back(str[i]);
            }
            else{
                break;
            }
        }
        for(int i = s.length() - 1; i >= 0; i--){
            s.push_back(s[i]);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends