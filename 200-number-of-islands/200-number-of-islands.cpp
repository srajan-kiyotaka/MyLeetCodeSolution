class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.first >= grid.size() && t.second >= grid[0].size()) continue;
            if(grid[t.first][t.second] == 'c') continue;
            grid[t.first][t.second] = 'c';
            if(t.second + 1 < grid[0].size() && grid[t.first][t.second + 1] == '1')
                q.push({t.first, t.second + 1});
            if(t.first + 1 < grid.size() && grid[t.first + 1][t.second] == '1')
                q.push({t.first + 1, t.second});
            if(t.second - 1 >= 0 && grid[t.first][t.second - 1] == '1')
                q.push({t.first, t.second - 1});
            if(t.first - 1 >= 0 && grid[t.first - 1][t.second] == '1')
                q.push({t.first - 1, t.second});
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int island = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    island++;
                    // cout << island << endl;
                    bfs(grid, i, j);
                }
            }
        }
        
        return island;
    }
};