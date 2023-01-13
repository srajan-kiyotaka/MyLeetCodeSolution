class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, string& s, int& ans){
        int longest = 0, second_longest = 0;
        for(int child: adj[node]){
            int child_longest = dfs(child, adj, s, ans);
            if(s[child] == s[node]) continue;
            if(longest < child_longest){
                second_longest = longest;
                longest = child_longest;
            }
            else if(second_longest < child_longest){
                second_longest = child_longest;
            }
        }
        ans = max(ans, longest + second_longest + 1);
        return longest + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, adj, s, ans);
        return ans;
    }
};