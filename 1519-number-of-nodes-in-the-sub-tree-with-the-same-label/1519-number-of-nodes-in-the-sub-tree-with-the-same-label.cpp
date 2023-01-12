class Solution {
public:
    vector<int> dfs1(int node, int parent, vector<vector<int>>& adj, string& labels,
                    vector<int>& ans){
        vector<int> notesCount(26);
        notesCount[labels[node] - 'a'] = 1;
        for(auto& child : adj[node]){
            if(child == parent) continue;
            vector<int> childCount = dfs1(child, node, adj, labels, ans);
            for(int i = 0; i < 26; i++){
                notesCount[i] += childCount[i];
            }
        }
        ans[node] = notesCount[labels[node] - 'a'];
        return notesCount;
    }

    vector<int> dfs2(int node, int parent, vector<vector<int>>& adj, string& labels,
                    vector<int>& ans) {
        vector<int> nodeCounts(26);
        nodeCounts[labels[node] - 'a'] = 1;
        for (auto& child : adj[node]) {
            if (child == parent) {
                continue;
            }
            vector<int> childCounts = dfs2(child, node, adj, labels, ans);
            for (int i = 0; i < 26; i++) {
                nodeCounts[i] += childCounts[i];
            }
        }
        ans[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i = 0; i < n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,0);
        dfs1(0, -1, adj, labels, ans);
        return ans;
    }
};