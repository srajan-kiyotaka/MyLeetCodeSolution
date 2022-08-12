class Solution {
public:
    int dfs(int root, vector<int>& manager, vector<int>& informTime, vector<int> adj[]){
        if(adj[root].size() == 0) return 0;
        int maxi = INT_MIN;
        for(auto i : adj[root]){
            maxi = max(maxi, dfs(i, manager, informTime, adj));
            // cout << "i: " << i << " max: " << maxi << endl;
        }
        return maxi + informTime[root];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            if(i != headID){
                adj[manager[i]].push_back(i);
            } 
        }
        // cout << "n : " << n<< endl;
        // for(int i = 0; i < n; i++){
        //     cout << "i : " << i << "~"; 
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dfs(headID, manager, informTime, adj);
    }
};