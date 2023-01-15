class Solution {
public:
    int find(vector<int>& parent, int node){
        if(parent[node] == node) return node;
        parent[node] = find(parent, parent[node]);
        return parent[node];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;
        vector<int> parent(n);
        unordered_map<int, int> max_element;
        unordered_map<int, int> frequency;

        // Build and fill the required Data Structures.
        for(int i = 0; i < n; i++){
            parent[i] = i;
            max_element[i] = vals[i];
            frequency[i] = 1;
        }

        // Sort the edges vector in increasing order.
        sort(edges.begin(), edges.end(), [&](const vector<int>& v1, vector<int>& v2){
            int a = max(max_element[v1[0]], max_element[v1[1]]);
            int b = max(max_element[v2[0]], max_element[v2[1]]);
            return a < b;
        });

        // ITERATE OVER ALL THE EDGES AND CALCULATE THE FINAL ANSWER.
        for(auto& edge: edges){
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if(max_element[x] == max_element[y]){
                parent[x] = y;
                ans += frequency[x] * frequency[y];
                frequency[y] += frequency[x];
            }
            else{
                if(max_element[x] > max_element[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                }
            }
        }
        return ans;
    }
};