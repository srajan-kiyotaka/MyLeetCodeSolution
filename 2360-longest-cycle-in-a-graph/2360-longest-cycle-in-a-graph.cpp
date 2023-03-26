class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n = edges.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            int length = 1;
            int j = edges[i];
            while(length <= n){
                // cout << "i = " << i << ", j = " << j << endl;
                if(j == -1) break;
                if(visited[j]) break;
                if(i == j){
                    ans = max(ans, length);
                    while(length--){
                        visited[j] = true;
                        j = edges[j];
                    }
                    break;
                }
                j = edges[j];
                length++;
            }
            // cout << "i = " << i << ", len = " << length << endl;
        }
        return ans;
    }
};