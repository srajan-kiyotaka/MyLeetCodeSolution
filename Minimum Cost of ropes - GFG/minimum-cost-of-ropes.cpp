//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Approach: Using a Min Heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long totalCost = 0;
        // Build the Min Heap
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
    
        while(pq.size() != 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long cost = a + b;
            totalCost += cost;
            pq.push(cost);
        }
        
        return totalCost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends