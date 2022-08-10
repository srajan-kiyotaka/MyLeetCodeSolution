class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                } 
            }
        }
        int primeter = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(grid[temp.first][temp.second] == 0) primeter++;
            else if(grid[temp.first][temp.second] == 1){
                if(temp.first + 1 < n){
                    q.push({temp.first + 1, temp.second});
                }
                else{
                    primeter++;
                }
                if(temp.first - 1 >= 0){
                    q.push({temp.first - 1, temp.second});
                }
                else{
                    primeter++;
                }
                if(temp.second + 1 < m){
                    q.push({temp.first, temp.second + 1});
                }
                else{
                    primeter++;
                }
                if(temp.second - 1 >= 0){
                    q.push({temp.first, temp.second - 1});
                }
                else{
                    primeter++;
                }
                grid[temp.first][temp.second] = -1;
            }
        }
        return primeter;
    }
};