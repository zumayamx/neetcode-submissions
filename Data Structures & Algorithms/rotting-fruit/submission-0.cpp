class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = (int)grid.size();
        int COLS = (int)grid[0].size();

        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1)
                    freshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        if (freshOranges == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!q.empty()) {
            int qs = (int)q.size();
            for (int i = 0; i < qs; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshOranges--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }

        if (freshOranges == 0)
            return minutes - 1;
        else
            return -1;
    }
};
