class Solution {
   public:
    void dfs(vector<vector<char>>& grid, set<pair<int, int>>& visited, int r, int c) {
        if (visited.find({r, c}) != visited.end()) return;
        int ROWS = (int)grid.size();
        int COLS = (int)grid[0].size();

        visited.insert({r, c});
        if (c > 0 && grid[r][c - 1] == '1') dfs(grid, visited, r, c - 1);
        if (c < COLS - 1 && grid[r][c + 1] == '1') dfs(grid, visited, r, c + 1);
        if (r > 0 && grid[r - 1][c] == '1') dfs(grid, visited, r - 1, c);
        if (r < ROWS - 1 && grid[r + 1][c] == '1') dfs(grid, visited, r + 1, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = (int)grid.size();
        int C = (int)grid[0].size();

        set<pair<int, int>> visited;
        int islands = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '1' && visited.find({i, j}) == visited.end()) {
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
