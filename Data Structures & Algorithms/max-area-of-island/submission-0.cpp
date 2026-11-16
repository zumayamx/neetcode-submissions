class Solution {
   public:
    int dfs(vector<vector<int>>& grid, set<pair<int, int>>& visited, int r, int c, int area) {
        if (visited.find({r, c}) != visited.end()) return 0;
        int ROWS = (int)grid.size();
        int COLS = (int)grid[0].size();

        visited.insert({r, c});
        if (c > 0 && grid[r][c - 1]) area += dfs(grid, visited, r, c - 1, 1);
        if (c < COLS - 1 && grid[r][c + 1]) area += dfs(grid, visited, r, c + 1, 1);
        if (r > 0 && grid[r - 1][c]) area += dfs(grid, visited, r - 1, c, 1);
        if (r < ROWS - 1 && grid[r + 1][c]) area += dfs(grid, visited, r + 1, c, 1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = (int)grid.size();
        int C = (int)grid[0].size();

        set<pair<int, int>> visited;
        int maxArea = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] && visited.find({i, j}) == visited.end()) {
                    int area = dfs(grid, visited, i, j, 1);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
