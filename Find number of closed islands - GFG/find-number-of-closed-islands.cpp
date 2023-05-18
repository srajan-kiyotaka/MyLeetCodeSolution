//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void bfs(int i, int j, int N, int M, vector<vector<int>>& matrix, vector<vector<int>>& vis) {
    vis[i][j] = 1;  // Mark the current cell as visited
    queue<pair<int, int>> q;
    q.push({i, j});  // Enqueue the starting point

    int delR[] = {0, -1, 0, 1};  // Offsets for row
    int delC[] = {-1, 0, 1, 0};  // Offsets for column

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {  // Explore neighboring cells in all four directions
            int nrow = row + delR[k];
            int ncol = col + delC[k];

            if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && matrix[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                // Check if neighboring cell is within bounds, unvisited, and a land cell
                vis[nrow][ncol] = 1;  // Mark the neighboring cell as visited
                q.push({nrow, ncol});  // Enqueue the neighboring cell
            }
        }
    }
}

int closedIslands(vector<vector<int>>& matrix, int N, int M) {
    vector<vector<int>> vis(N, vector<int>(M, 0));  // Create a 2D visited array, initially set to 0

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && matrix[i][j] == 1) {
                // If a land cell is located on the boundary, perform BFS to mark connected land cells
                bfs(i, j, N, M, matrix, vis);
            }
        }
    }

    int c = 0;  // Count of closed islands

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 1 && vis[i][j] == 0) {
                // If a land cell is unvisited, it indicates a closed island
                c++;
                bfs(i, j, N, M, matrix, vis);
            }
        }
    }

    return c;
}
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends