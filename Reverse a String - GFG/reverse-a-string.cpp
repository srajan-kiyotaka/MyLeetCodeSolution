//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
         string p;
        int i=0;
        stack<char>s;
        while(i<str.size()){
            s.push(str[i]);
            i++;
        }
        while(!s.empty()){
            p+=s.top();
            s.pop();
        }
        return p;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends