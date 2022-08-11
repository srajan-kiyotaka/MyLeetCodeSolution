class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& visited, int node){
        if(!visited[node]){
            visited[node] = true;
            if(adj[node].size() != 0){
                vector<int> temp = adj[node];
                for(auto i : temp){
                    dfs(adj, visited, i);
                }
            }
            return;
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int edge = connections.size();
        vector<bool> visited(n, false);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int component = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                component++;
                dfs(adj, visited, i);
            }
        }
        int reden = edge - (n - 1) + (component - 1);
        if(reden >= (component - 1)){
            return component - 1;
        }
        return -1;
    }
};