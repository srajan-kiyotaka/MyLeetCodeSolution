//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

static bool compare(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
        return ((a.second.second == b.second.second)?(a.first < b.first):(a.second.second < b.second.second));
    }

class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
        // Greedy Approach
        // Time Complexity: O()
        // Space Complexity: O()
        vector<pair<int, pair<int, int>>> meeting;
        for(int i = 0; i < n; i++){
            meeting.push_back(make_pair(i+1, make_pair(S[i], F[i])));
        }
        // Sort According to the End Time of the Metting
        sort(meeting.begin(), meeting.end(), compare);
        vector<int> ans;
        int endtime = -1;
        for(int i = 0; i < n; i++){
            if(endtime < meeting[i].second.first){
                ans.push_back(meeting[i].first);
                endtime = meeting[i].second.second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends