class Solution {
public:
    bool closedIsland(vector<vector<int>>& grid, int row, int colm, int& cellCount){
        int rows = grid.size();
        int colms = grid[0].size();
        if(row >= rows || row < 0 || colm < 0 || colm >= colms) return false;
        if(grid[row][colm] == 0 || grid[row][colm] == -1) return true;
        grid[row][colm] = -1;
        cellCount++;
        bool ans = closedIsland(grid, row + 1, colm, cellCount);
        ans = closedIsland(grid, row - 1, colm, cellCount) && ans;
        ans = closedIsland(grid, row, colm - 1, cellCount) && ans;
        ans = closedIsland(grid, row, colm + 1, cellCount) && ans;
        return ans;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int colms = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colms; j++){
                if(grid[i][j] == 1){
                    int cellCount = 0;
                    if(closedIsland(grid, i, j, cellCount)){
                        ans += cellCount;
                    } 
                }
            }
        }
        return ans;
    }
};