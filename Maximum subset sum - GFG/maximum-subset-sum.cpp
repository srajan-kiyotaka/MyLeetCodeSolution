//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(2, vector<long long> (2, 0));
        for (int i = N - 1; i >= 0; i--)
        {
            dp[i%2][1] = max(dp[!(i%2)][0], A[i] + dp[!(i%2)][1]);
            dp[i%2][0] = A[i] + dp[!(i%2)][1];
        }
        return dp[0][1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends