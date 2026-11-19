// DP APPROACH BOTTOM UP TABULATION
// The key is to think about
// what means dp[i] in this case means
// for a given i which is the maximun
// profit util now. And that profit
// is defined two cases, take the
// current house nums[i] + two
// houses behind me, or only take
// the house behind me. That is max(nums[i] + dp[i - 2], dp[i - 1])
// and I'm goint to explain how I conclude that.
//
// Take a simple case with ony one house with 1 of profit. [1]
// What is the maximum profit can we obtain from that?
// Is 1, only rob that house, is a base case, for i = 0, the maximun
// profit is nums[i];
//
// Let's add another house with value 2, so our array would be [1, 2]
// What is the maximun profit from here under the restrictions.
//
// We said that for i = 0, the maximum profit is nums[i] = 1, but now
// what is the maximun profit for i = 1, if we know we cannot steal
// a house that is adjacent to me, I have two options, take the profit
// behind me only, that is the profit of i = 0, that is 1 OR don't take
// that profit and steal this house, what is maximum, the profit from 
// the house behind me? (1) or the profit from steal this house? (2),
// obviusly the profit from this house, IN THIS CASE ONLY, the profit
// is the least important thing, the base case is what matters. For
// an array of length two, we only have two options take one or another.

// But now, let's add another house to our array, with value 3,
// so our array would be [1, 2, 3], same question what is the
// maximun profit from of this?
//
// We already computed the maximun profit of [1, 2], that is
// dp = [1, 2], now for i = 2, what is the maximun profit
// we can obtain until that house, we have the same two options
// as before, we can take the profit of the house behind me OR
// take this house and the profit from two houses behind me
// why two hoses behind me? Because trace it, le't say we hare in
// the house 0 (value 1), forgive the dp array for a moment
// in that house we have two options take the current house and
// go two houses ahead, or skip the current house and the next one
// Which one is more convenient for us? Obviouly take this house
// and the one two houses ahead of me. So is the same condition
// seeing from another perspective, with that in mind
// we can say for a given i, the maximun profit is the max
// between take this current house and the profit from
// two houses behind me or only take the profit behind me.
// With that, for i = 2, the max profit for that house
// take that house and the profit from the first house
// that is 1 + 3, equals 4, so our dp, would be = [1, 2, 4]
// which is the correct answer for an array [1, 2, 3]
// take the first and last house.
//
// But futhermore, this tells us that, we only care about
// given a i, for the last two maximum profit from houses.
//
// Pseudocode:
//
// We define our base cases.
// if nums contains one element, return that element
// if nums constains two elements, we return the max between that two
// if we have more elements, we intialize our dp array
// with 3 boxes, {nums[0], max(nums[0], nums[1]), -1} -1 because is the number
// we are going to compute

// (IN REALITY, I THINK WE ONLY NEED TWO BOXES, BECAUSE WE SHIFT LEFT ONE OF THEM)
// itialize i = 2,
// then while (i <= n) because we need to iterate over all houses, (at least one step by house)
// int tmp = dp[1];
//  dp[1] = max(nums[i] + dp[0], dp[1]);
// shif left the tmp element
// dp[0] = tmp;
// i ++
// return dp[1];
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp = {nums[0], max(nums[0], nums[1])};

        int i = 2;
        while (i < n)
        {
            int tmp = dp[1];
            dp[1] = max(nums[i] + dp[0], dp[1]);
            dp[0] = tmp;
            i++;
        }

        return dp[1];
    }
};
