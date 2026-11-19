// MEMOIZATION APPROACH

class Solution {
   public:
    int dfs(vector<int>& nums, int& n, vector<int>& memo, int i) {
        if (i >= n) return 0;

        if (memo[i] >= 0) return memo[i];

        memo[i] = max(nums[i] + dfs(nums, n, memo, i + 2), dfs(nums, n, memo, i + 1));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> memo(n, -1);
        return dfs(nums, n, memo, 0);
    }
};
