//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> a, string pat) {
        
        vector<pair<string,string>>b;vector<string>s;
        string res="";
        int i,j ,c=0;
        for(i=0;i<a.size();i++)
        { res="";
            for(j=0;j<a[i].size();j++)
            {
                if(a[i][j]>=65 && a[i][j]<=90)
                {
                    res+=a[i][j];
                }
            }
            b.push_back(make_pair(a[i], res));
        }
        
       for(auto &x: b)
       {
           if(!x.second.find(pat))
           {
               s.push_back(x.first);
             c++;
           }
           
       }
       if(c==0)
       s.push_back("-1");
       sort(s.begin(),s.end());
       return s;
       
        
        
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends