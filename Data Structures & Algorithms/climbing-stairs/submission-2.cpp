// DP APPROCH BOTTOM UP TABULATION
class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp = {1, 1};
        int i = 2;

        while (i <= n)
        {
            int tmp = dp[1];
            // The paths from n - 2 and n - 1
            dp[1] = dp[0] + dp[1];
            // Shift the last result to left,
            // because in the next iteration it will be
            // n - 2 paths
            dp [0] = tmp;
            i++;
        }
        return dp[1];
    }
};
