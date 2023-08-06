//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    vector<string> ans;
    void fn(string &s, int mask, string &res)
    {
        if(mask == 0) 
        {
            ans.push_back(res);
            return;
        }
        for(int i = 0;i<=5;i++)
        {
            if(mask&(1<<i))
            {
                res.push_back(s[i]);
                fn(s,mask&(~(1<<i)),res);
                res.pop_back();
            }
        }
    }
    vector<string> permutation(string S)
    {
        string res = "";
        fn(S,(1<<S.length()) - 1, res);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends