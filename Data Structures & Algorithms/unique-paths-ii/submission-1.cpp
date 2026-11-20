// MEMOIZATION APPROACH

class Solution {
   public:
    int memoization(vector<vector<int>>& grid, vector<vector<int>>& memo, int r, int c, int& ROWS,
                    int& COLS) {
        if (r == ROWS || c == COLS) return 0;
        if (grid[r][c] == 1) return 0;
        if (memo[r][c] > 0) return memo[r][c];
        if (r == ROWS - 1 && c == COLS - 1) return 1;

        memo[r][c] = memoization(grid, memo, r + 1, c, ROWS, COLS) +
                     memoization(grid, memo, r, c + 1, ROWS, COLS);
        return memo[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = (int)obstacleGrid.size();
        int COLS = (int)obstacleGrid[0].size();
        vector<vector<int>> memo(ROWS, vector<int>(COLS));
        return memoization(obstacleGrid, memo, 0, 0, ROWS, COLS);
    }
};