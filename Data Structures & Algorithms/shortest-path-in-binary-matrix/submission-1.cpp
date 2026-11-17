class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = (int)grid.size();
        int COLS = (int)grid[0].size();

        set<pair<int, int>> v;
        queue<pair<int, int>> q;

        if (grid[0][0] == 0) {
            q.push({0, 0});
            v.insert({0, 0});
        } else
            return -1;

        int length = 1;
        while (!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == ROWS - 1 && c == COLS - 1) return length;

                vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
                                               {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                        v.find({nr, nc}) == v.end() && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        v.insert({nr, nc});
                    }
                }
            }
            length++;
        }

        return -1;
    }
};