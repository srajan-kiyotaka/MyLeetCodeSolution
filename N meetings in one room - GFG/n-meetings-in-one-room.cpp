//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Approach: Greedy
        vector<pair<int,int>> meeting;
        for(int i = 0; i < n; i++){
            meeting.push_back(make_pair(start[i], end[i]));
        }
        // Sort according to the  start time in increasing order.
        sort(meeting.begin(), meeting.end(), [&](pair<int,int> &a, pair<int,int> &b){
            return (a.second < b.second);
        });
        int ans = 1;
        int endtime = meeting[0].second;
        for(int i = 1; i < n; i++){
            if(meeting[i].first > endtime){
                ans++;
                endtime = meeting[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends