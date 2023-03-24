class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        /* BFS Approch */
        /*
        Make sure that all nodes that are connected to 0 have all edges coming into them.
        E.g. if nodes x and y are connected to 0. After first step, there will be edges 
        from x to 0 and y to 0. Now we want to make sure that all nodes that are directly 
        connected to x, must have an edge coming into x. Similarly for y. If we keep on 
        doing this recursively, we will get the answer at the end. Along the way, we will 
        keep counting the edges that we reversed.
        */
        /* 
        Here I am storing a pair in the adjusency matrix, which stores the connected node,
        and the direction of connection, i.e. true for outgoing and false for incoming. 
         */
        for(int i = 0; i < n-1; i++){
            pair<int, bool> temp;
            temp.first = connections[i][1];
            temp.second = true;
            adj[connections[i][0]].push_back(temp);
            temp.first = connections[i][0];
            temp.second = false;
            adj[connections[i][1]].push_back(temp);
        }
        // BFS Approch.
        int count = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr]) continue;
            visited[curr] = true;
            for(auto it : adj[curr]){
                if(!visited[it.first]){
                    if(it.second){
                        // cout << "curr = " << curr << ", connect = " << it.first << endl;
                        count++;
                    }
                    q.push(it.first);
                }
            }
        }
        return count;
    }
};