class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = (int)grid.size();
        int COLS = (int)grid[0].size();
        queue<pair<int, int>> q;

        if (grid[0][0] == 0) {
            q.push({0, 0});
            grid[0][0] = 1;
        } else
            return -1;

        int length = 1;
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
                                       {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
        while (!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == ROWS - 1 && c == COLS - 1) return length;

                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            length++;
        }

        return -1;
    }
};