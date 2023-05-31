//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int, int> map;
        for(int i = 0; i<n; i++) map[arr[i]]++;
        int min_freq = INT_MAX;
        int maxi = INT_MIN;
        for(auto x : map) 
            min_freq = min(min_freq, x.second);
        for(auto x : map) 
            if(x.second == min_freq) 
                maxi = max(maxi, x.first);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends