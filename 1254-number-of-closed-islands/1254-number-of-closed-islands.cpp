class Solution {
public:
    bool findCloseIsland(vector<vector<int>>& grid, pair<int, int> position){
        int rows = grid.size();
        int columns = grid[0].size();
        // base case
        if(position.first < 0 || position.first >= rows || position.second < 0 || position.second >= columns) return false;

        if(grid[position.first][position.second] == 1 || grid[position.first][position.second] == -1) return true;
        // cout << "i = " << position.first << ", j = " << position.second << endl;
        grid[position.first][position.second] = -1;
        pair<int, int> next;
        next.first = position.first - 1;
        next.second = position.second;
        bool ans = findCloseIsland(grid, next);
        next.first = position.first;
        next.second = position.second  - 1;
        ans = (findCloseIsland(grid, next)) && ans;
        next.first = position.first + 1;
        next.second = position.second;
        ans = (findCloseIsland(grid, next)) && ans;
        next.first = position.first;
        next.second = position.second + 1;
        ans = (findCloseIsland(grid, next)) && ans;
        return ans;
    }

    void print(vector<vector<int>>& grid){
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rows; i++){
            pair<int, int> init;
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 0){
                    init.first = i;
                    init.second = j;
                    ans += (findCloseIsland(grid, init))?1:0;
                    // print(grid);
                    // cout << " ~ " << endl;
                }
            }
        }
        return ans;
    }
};