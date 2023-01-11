class Solution {
public:
    int dfs_tree(int parent, int node, vector<vector<int>>& adj, vector<bool>& hasApple){
         int total = 0;
         int child_time = 0;
         for(auto child: adj[node]){
             if(child == parent) continue;
             child_time = dfs_tree(node, child, adj, hasApple);
             if(child_time || hasApple[child]) total += child_time + 2;
         }
         return total;
    }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n, vector<int>(0));
        int i = 0;
        while(i < edges.size()){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            i++;
        }

        return dfs_tree(-1, 0, adj, hasApple);
    }
};