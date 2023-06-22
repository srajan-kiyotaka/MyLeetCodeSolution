//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool solver(int n, int arr[], int index, int target, vector<vector<int>> &dp){
        // Base Case
        if(target == 0) return true;
        if(index >= n || target < 0) return false;
        if(dp[index][target] != -1) return dp[index][target];
        // Exclude or Include
        bool exc = solver(n, arr, index + 1, target, dp);
        bool inc = solver(n, arr, index + 1, target - arr[index], dp);
        dp[index][target] = (exc or inc);
        return (exc or inc);
    }
public:
    int equalPartition(int N, int arr[])
    {
        // DP: Bottom Up Approach: Tabulation.
        // Time Complexity: O(N*Total)
        // Space Complexity: O(N*Total)
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        if(totalSum & 1) return 0;
        int target = totalSum/2;
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));
        for(int i = 0; i <= N; i++){
            dp[i][0] = 1;
        }
        for(int i = N - 1; i >= 0; i--){
            for(int j = 0; j <= target; j++){
                dp[i][j] = dp[i + 1][j];
                if(j - arr[i] >= 0)
                    dp[i][j] = dp[i][j] or dp[i+1][j - arr[i]];
            }
        }
        return dp[0][target];
    }
};

/*

class Solution{
private:
    bool solver(int n, int arr[], int index, int target, vector<vector<int>> &dp){
        // Base Case
        if(target == 0) return true;
        if(index >= n || target < 0) return false;
        if(dp[index][target] != -1) return dp[index][target];
        // Exclude or Include
        bool exc = solver(n, arr, index + 1, target, dp);
        bool inc = solver(n, arr, index + 1, target - arr[index], dp);
        dp[index][target] = (exc or inc);
        return (exc or inc);
    }
public:
    int equalPartition(int N, int arr[])
    {
        // DP: Top Down Approach: Recursion + Memoization.
        // Time Complexity: O(N*Total)
        // Space Complexity: O(N*Total)
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        if(totalSum & 1) return 0;
        vector<vector<int>> dp(N, vector<int>((totalSum/2) + 1, -1));
        return (solver(N, arr, 0, totalSum/2, dp))?(1):(0);
    }
};

*/

/*

class Solution{
private:
    bool solver(int n, int arr[], int index, int target){
        // Base Case
        if(target == 0) return true;
        if(index >= n || target < 0) return false;
        // Exclude or Include
        return (solver(n, arr, index + 1, target) || solver(n, arr, index + 1, target - arr[index]));
    }
public:
    int equalPartition(int N, int arr[])
    {
        // Recursive Approach.
        // Time Complexity: O(2^N*Total)
        // Space Complexity: O(N*Total)
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        if(totalSum & 1) return 0;
        return (solver(N, arr, 0, totalSum/2))?(1):(0);
    }
};

*/


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends