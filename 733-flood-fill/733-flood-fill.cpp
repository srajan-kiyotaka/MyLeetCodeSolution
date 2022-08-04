class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int change){
        if(image.size() <= sr || sr < 0) return;
        if(image[0].size() <= sc || sc < 0) return;
        if(image[sr][sc] != change || image[sr][sc] == color) return;
        image[sr][sc] = color;
        fill(image, sr+1, sc, color, change);
        fill(image, sr, sc+1, color, change);
        fill(image, sr-1, sc, color, change);
        fill(image, sr, sc-1, color, change);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};