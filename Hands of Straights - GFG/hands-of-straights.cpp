//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        if(n % groupSize != 0) return false; 
        if(n == 1 or groupSize == 1) return true;
        
        sort(hand.begin(), hand.end());
        vector<int> vis(n);
        
        int grp = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            
            vis[i] = 1;
            int countElements = 1, prev = hand[i];
            for(int j = i + 1; j < n; j++) {
                if(hand[j] == prev + 1) {
                    vis[j] = 1;
                    prev = hand[j];
                    countElements++;
                }
                
                if(countElements == groupSize) {
                    grp++;
                    break;
                }
            }
        }
        
        return grp == n / groupSize;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends