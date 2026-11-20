// DP BOTTOM UP

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int ROWS = (int)text1.size();
        int COLS = (int)text2.size();

        vector<int> prevRow(COLS + 1);
        vector<int> currRow(COLS + 1);

        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c = COLS - 1; c >= 0; c--) {
                if (text1[r] == text2[c]) {
                    currRow[c] = 1 + prevRow[c + 1];
                } else {
                    currRow[c] = max(prevRow[c], currRow[c + 1]);
                }
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};
