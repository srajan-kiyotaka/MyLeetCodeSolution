//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int vis[101] = {0};
        
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({arr[i].dead, arr[i].profit});
        }
        
        sort(v.begin(), v.end(), comp);
        
        int mxProfit = 0, countJobs = 0;
        for(auto it: v){
            if(!vis[it.first]){
                vis[it.first] = 1;
                countJobs++;
                mxProfit += it.second;
            }
            else{
                int i = it.first -1;
                while(i > 0){
                    if(!vis[i]){
                        vis[i] = 1;
                        countJobs++;
                        mxProfit += it.second;
                        break;
                    }
                    i--;
                }
            }
        }
        return {countJobs, mxProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends