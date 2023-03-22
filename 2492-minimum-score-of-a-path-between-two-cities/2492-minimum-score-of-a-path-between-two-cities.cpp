class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // First make a adjacency matrix
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = INT_MAX;
        
        // We will search only in the connected graph.
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int city = q.front();
            q.pop();
            if(visited[city]){
                continue;
            }
            visited[city] = true;
            for(auto it : adj[city]){
                q.push(it);
            }
        }

        

        // now search the minimum distance on the visited city.
        for(int i = 0; i < roads.size(); i++){
            if(visited[roads[i][0]] && visited[roads[i][1]] && (roads[i][2] < ans)){
                ans = roads[i][2];
            }
        }
        return ans;
    }
};