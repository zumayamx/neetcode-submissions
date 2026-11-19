// MEMOIZATION APPROACH, USING A MEMO MATRIX

class Solution {
public:
    int dfs(vector<vector<int>>& memo, int r, int c, int R, int C)
    {
        if (r == R  || c == C) return 0;
        if (r == R - 1 && c == C - 1) return 1;

        if (memo[r][c] > 0) return memo[r][c];

        memo[r][c] = dfs(memo, r + 1, c, R, C) + dfs(memo, r, c + 1, R, C);
        return memo[r][c];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n));
        return dfs(memo, 0, 0, m, n);
    }
};
