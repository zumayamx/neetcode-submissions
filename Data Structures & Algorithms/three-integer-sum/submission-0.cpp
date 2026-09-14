/**
 * Okay, I have read the documentation and the approach
 * goes in the next manner.
 *
 * First, we need to form triplets in a way
 * that all the elements sum will be 0.
 *
 * So, after reading the documentation the first
 * approach that comes to my mind is iterate over each
 * num in nums and find a pair that satisfies the next
 * ecuation.
 *
 * num1 + num2 + num3 = 0
 *
 * If we take num1 as our current number in the
 * iteration of numbers, how num2 and num3 must be
 * moved in the ecuation?
 *
 * num1 = -(num2 + num3)
 *
 * or
 *
 * -num1 = num2 + num3
 *
 * So, for each number in the nums array we need to find two
 * numbers (a pair) that satisfies that ecuation without
 * taking the repeated ones into account. 
 *
 * We could sort the input array to apply a two pointer
 * approach that finds for that pair.
 *
 * As the numbers are sorted, we could define a rule
 * if the sum of num2 and num3 is greater than
 * our current number, then we decrement the right pointer
 * since we need a smaller number in the other case
 * we update the left pointer since we need a lager number.
 *
 * Now, about duplicates.
 *
 * There is possible to get a duplicate triplet,
 * one case is to have one or more repetitions of
 * num2 and num3 in the array, for example: 
 *
 * nums = [-4, 2, 2, 1, 2, 2]
 *
 * So say our current number is -4, and our two poiters
 * are at nums[1] and nums[5], that is 2 and 2
 *
 * In that case one triplet is created and saved
 *
 * [-4, 2, 2]
 * 
 * So, we move the pinters left and right inner in the window,
 * now nums[2] and nums[4], that is 2 and 2
 * 
 * That case acomplish the condition so another tripler is 
 * created
 *
 * [-4, 2, 2]
 *
 * But this triplet is duplicated, is equal to the previous one.
 * We need a way to avoid this duplicates, one way is to move
 * the left or the right pointer if the next element is equal.
 *
 * In this case we move the left element by one, it not matters
 * what r value will be, because for one pair l and r that
 * accomplished the sum there is only one r value that acomplish
 * the ecuation, so if the left element is equal by mathematics
 * a valid triplet would be with the same r as the previous one.
 *
 * This check is for the current i of the number
 * another check is for the next i in the array
 * is guaranted that for the next i that is same
 * to the previous i, all posible triplers
 * were explored.
 *
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int s = nums[i] * -1;
            int l = i + 1; int r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum < s) l++;
                else if (sum > s) r--;
                else
                {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }

        return res;
    }
};
