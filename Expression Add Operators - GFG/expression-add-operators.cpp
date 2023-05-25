//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     void f(int ind,string s,int target,vector<string> &ans,string tmp,long long prev,long long res)
  {
      if(ind==s.size())
      {
          if(res==target)
          ans.push_back(tmp);
          
          return;
      }
      string st="";
      long long curr=0;
      for(int i=ind;i<s.size();i++)
      {
          if(i>ind && s[ind]=='0')
          break;
          st+=s[i];
          curr=curr*10+s[i]-'0';
          if(ind==0)
          f(i+1,s,target,ans,tmp+st,curr,curr);
          else
          {
              f(i+1,s,target,ans,tmp+"+"+st,curr,res+curr);
              f(i+1,s,target,ans,tmp+"-"+st,-curr,res-curr);
              f(i+1,s,target,ans,tmp+"*"+st,prev*curr,res-prev+prev*curr);
          }
      }
      return;
  }
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        string tmp="";
        long long prev=0;
        f(0,s,target,ans,tmp,prev,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends