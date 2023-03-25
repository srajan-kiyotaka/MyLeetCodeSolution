class Solution {
public:
    int dfs(int curr, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[curr]) return 0;
        int sum = 1;
        visited[curr] = true;
        for(auto it : adj[curr]){
            if(!visited[it]){
                sum += dfs(it, adj, visited);
            }
        }
        return sum;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        /* Count the number of islands */
        /*
        Total possible pairs = n*(n-1)/2
        now subtract total pairs possible in the same island
        that is also m*(m-1)/2, where m is the total number of 
        nodes in a island.
        count the island using dfs.
        */
        long long totalCount = (1ll)*n*(n-1)/2;
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                long long temp = dfs(i, adj, visited);
                totalCount -= temp*(temp-1)/2;
            }
        }
        return totalCount;
    }
};

/*

if(edges.size() == 0){
            return (1ll)*((1ll)*n*(n-1)/2);
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans.push_back(dfs(i, adj, visited));
            }
        }
        if(ans.size() == 1) return 0;
        long long count = 0;
        for(int i = 0; i < ans.size(); i++){
            for(int j = i+1; j < ans.size(); j++){
                count += (1ll)*ans[i]*ans[j];
            }
        }
        return count;
    }

*/