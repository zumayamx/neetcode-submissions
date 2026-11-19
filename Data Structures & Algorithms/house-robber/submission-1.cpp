// MEMOIZATION APPROACH

class Solution {
   public:
    int dfs(vector<int>& nums, int& n, vector<int>& memo, int i) {
        if (i >= n) return 0;
        if (i == n - 1) return nums[i];

        if (memo[i] > 0) return memo[i];

        memo[i] = max(nums[i] + dfs(nums, n, memo, i + 2), dfs(nums, n, memo, i + 1));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return nums[0];
        vector<int> memo(n);
        return dfs(nums, n, memo, 0);
    }
};
