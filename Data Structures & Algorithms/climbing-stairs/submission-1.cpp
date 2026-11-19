// MEMOIZATION APPROACH
/*
We need to mantain a memo (vector) that saves
the posible paths (the different ways to sum one's and two's)
to reach n exactly.

It's like to say, from this number how many different ways of sum one's and
two's exists to reach n number?


*/
class Solution {
    int dfs(int i, int& target, vector<int>& memo)
    {
        if (i == target) return 1;
        else if (i > target) return 0;
        
        if (memo[i] > 0) return memo[i];
        memo[i] = dfs(i + 1, target, memo) + dfs(i + 2, target, memo);
        return memo[i];
    }
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        vector<int> memo(n);
        return dfs(0, n, memo);
    }
};
