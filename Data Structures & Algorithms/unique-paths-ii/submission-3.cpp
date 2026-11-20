// DP BOTTOM UP APPROACH

// FAILED CASE
//
//  [0,0,0],
//  [0,0,1],
//  [0,1,0]
// SOLVED WITH AN EXTRA COL 

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = (int)obstacleGrid.size();
        int COLS = (int)obstacleGrid[0].size();

        vector<int> prevRow(COLS+1);
        vector<int> currRow(COLS+1);

        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c = COLS - 1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 1) {
                    currRow[c] = 0;
                } else if (r == ROWS - 1 && c == COLS - 1)
                    currRow[c] = 1;
                else
                    currRow[c] = prevRow[c] + currRow[c + 1];
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};