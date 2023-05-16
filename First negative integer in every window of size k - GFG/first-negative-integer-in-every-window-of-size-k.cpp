//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    vector<long long> ans;
    int j = 0;
    while(j < N && A[j] >= 0){j++;}
    for(int i = 0; i <= (N - K); i++){
        if((j - i) < K){
            ans.push_back(A[j]); 
        }
        else{
            ans.push_back(0);
        }
        if(i == j){
            j++;
            while(j < N && A[j] >= 0){j++;}
        }
    }
    return ans;
 }
 
 /*
 
    // Sliding Window Approach
    deque<long long int> dqu;
    // Create the first window
    for(int i = 0; i < K; i++){
        if(A[i] < 0){
            dqu.push_back(i);
        }
    }
    vector<long long> ans;
    if(!dqu.empty()){
        ans.push_back(A[dqu.front()]); 
    }
    else{
        ans.push_back(0);
    }
    // Slide the window
    for(int i = K; i < N; i++){
        // Delete the front element
        if(!dqu.empty()){
            if(dqu.front() == (i - K)){
                dqu.pop_front();
            }
        }
        // Add new element
        if(A[i] < 0) dqu.push_back(i);
        // Add the ans
        if(!dqu.empty()){
            ans.push_back(A[dqu.front()]); 
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
 
 */