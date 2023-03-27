class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            Approch: 
            Is to update the grid node value from the 
            minimum value required to reachred that node 
            from the top left corner node.
        */
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j != 0){
                    grid[i][j] += grid[i][j-1];
                }
                else if(i != 0 && j == 0){
                    grid[i][j] += grid[i-1][j];
                }
                else if(i != 0 && j != 0){
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }

        return grid[n-1][m-1];
    }
};

/* DFS Simple Solution

int dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        return grid[i][j] + min(dfs(grid, i+1, j), dfs(grid, i, j+1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0);
    }

*/