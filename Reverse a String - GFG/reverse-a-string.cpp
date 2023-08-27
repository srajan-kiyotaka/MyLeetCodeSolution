//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

#include <string>
// For the reverse function


class Solution
{
    public:
    string reverseWord(string str)
    {
       
        int length= str.length();

       // str.length as the name suggests...checks the length of string.....Example=geeks...length=5 
       
         string s="";

        for(int i=length-1;i>=0;i--)        //length-1 because of array serial 4,3,2,1,0
        {
            s+=str[i];
           // ""+s=s...s+k=sk...sk+e=ske...ske+e=skee...skee+g=skeeg
        }
        return s;
       //now s= skeeg  ----->geeks
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