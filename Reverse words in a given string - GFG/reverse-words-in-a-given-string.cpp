//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
        string ans = "";
        string word = "";
        for(int i = 0; i < n; i++){
            if(S[i] == '.'){
                ans = word + '.' + ans;
                word = "";
            }
            else{
                word = word + S[i];
            }
            if(i == n - 1 && word.length() != 0){
                ans = word + '.' + ans;
            }
        }
        ans.erase(ans.end() -1, ans.end());
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends