class Solution {
public:
    // Returns true if all the values in the matrix are the same; otherwise, false.
    bool sameValue(vector<vector<int>>& grid, int x1, int y1, int length) {
        for (int i = x1; i < x1 + length; i++) {
            for (int j = y1; j < y1 + length; j++)
                if (grid[i][j] != grid[x1][y1])
                    return false;
        }
        return true;
    }
    
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
        // Return a leaf node if all values are the same.
        if (sameValue(grid, x1, y1, length)) {
            return new Node(grid[x1][y1], true);
        } else {
            Node* root = new Node(false, false);

            // Recursive call for the four sub-matrices.
            root -> topLeft = solve(grid, x1, y1, length / 2);
            root -> topRight = solve(grid, x1, y1 + length / 2, length / 2);
            root -> bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
            root -> bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);

            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};