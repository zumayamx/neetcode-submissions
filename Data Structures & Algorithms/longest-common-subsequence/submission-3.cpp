class Solution {
   public:
    int memoization(vector<vector<int>>& memo, string& t1, string& t2, int p1, int p2, int& T1_LEN,
                    int& T2_LEN) {
        if (p1 == T1_LEN || p2 == T2_LEN) return 0;
        if (memo[p1][p2] >= 0) return memo[p1][p2];
        if (t1[p1] == t2[p2]) {
            memo[p1][p2] = 1 + memoization(memo, t1, t2, p1 + 1, p2 + 1, T1_LEN, T2_LEN);
            return memo[p1][p2];
        }
        memo[p1][p2] = max(memoization(memo, t1, t2, p1 + 1, p2, T1_LEN, T2_LEN),
                           memoization(memo, t1, t2, p1, p2 + 1, T1_LEN, T2_LEN));
        return memo[p1][p2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int T1_LEN = (int)text1.size();
        int T2_LEN = (int)text2.size();
        vector<vector<int>> memo(T1_LEN, vector<int>(T2_LEN, -1));
        return memoization(memo, text1, text2, 0, 0, T1_LEN, T2_LEN);
    }
};
