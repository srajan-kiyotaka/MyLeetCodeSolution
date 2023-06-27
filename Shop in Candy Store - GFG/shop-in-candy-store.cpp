//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Greedy Approach.
        // sort the prices.
        sort(candies, candies+n);
        // Minimum Possible Answer
        int mini = 0;
        int limit = n;
        for(int i = 0; i < limit; i++){
            mini += candies[i];
            limit = limit - k;
        }
        // Maximum Possible Answer
        int maxi = 0;
        limit = 0;
        for(int i = n-1; i >= limit; i--){
            maxi += candies[i];
            limit = limit + k;
        }
        return {mini, maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends