//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<int> dp(target+1,0);
        for(int i=0;i<N;i++){
            if(coins[i]<=target){
                dp[coins[i]]=1;
            }
        }
        for(int i=1;i<K;i++){
            vector<int> a(target+1,0);
            for(int j=0;j<=target;j++){
                if(dp[j]==1){
                    for(int l=0;l<N;l++){
                        if((j+coins[l])<=target){
                            a[j+coins[l]]=1;
                        }
                    }
                }
            }
            dp=a;
            // for(int j=0;j<=target;j++){
            //     cout<<dp[j]<<" ";
            // }cout<<endl;
        }
        return (dp[target]==1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends