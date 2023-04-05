//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        
        map<int,int>m;
        int count=0;
        for(int i=0;i<N;i++)
        {
            m[arr[i]]++;
        }
        for(int i=0;i<N;i++)
        {
            if(arr[i]==1)
            {
                if(m[arr[i]]>1)return N;
                else
                return N-1;
            }
            if(m[arr[i]]>1)
            {
                count++;
            }
            else
            {
                for(auto it=m.begin();it!=m.end();it++)
                {
                    int x=it->first;
                    if(x!=arr[i])
                    {
                        if(arr[i]%x==0)
                        {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends