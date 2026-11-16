class Solution {
   private:
    void dfs(vector<vector<int>>& image, int r, int c, int& prevColor, int& newColor) {
        int ROWS = (int)image.size();
        int COLS = (int)image[0].size();

        image[r][c] = newColor;

        if (c > 0 && image[r][c - 1] == prevColor) dfs(image, r, c - 1, prevColor, newColor);
        if (c < COLS - 1 && image[r][c + 1] == prevColor) dfs(image, r, c + 1, prevColor, newColor);
        if (r > 0 && image[r - 1][c] == prevColor) dfs(image, r - 1, c, prevColor, newColor);
        if (r < ROWS - 1 && image[r + 1][c] == prevColor) dfs(image, r + 1, c, prevColor, newColor);
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        if (prevColor == color) return image;
        dfs(image, sr, sc, prevColor, color);
        return image;
    }
};