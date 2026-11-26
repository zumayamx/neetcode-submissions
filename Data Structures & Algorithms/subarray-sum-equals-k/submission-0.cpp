// THE KEY IDEA IS TO THINK
// ABOUT HOW YOU CAN
// CHECK HOW MANY SUBARRAYS
// WHOSE SUM IS EQUAL
// TO THE DIFERRENCE BETWEEN
// THE CURRENT PREFIX SUM - K
// BECAUSE THAT MEANS THERE EXIST
// A CURRENT SUBARRAY WHOSE SUM
// IS EQUAL TO K

// THE {0, 1} INITIALIZATION
// OF THE HASH MAP IS AN EDGE CASE
// CONSIDER [1, 1, 1] K = 3,
// THE ENTIRE ARRAY IS A VALID
// SOLUTION, SO IN THE PFX SUM OF
// nums[2] IS EQUAL TO 3, 3 - K
// is 3 - 3, EQUAL TO 0, THERE IS
// ONE SUBARRAY, THAT 0 HAS THE
// COUNT OF 1, IS CONSIDEREING
// THE ENTIRE SUB ARRAY AS A
// SOLUTION, ACTUALLY IT WORKS
// WITH ALL SUB ARRAY FROM LEFT TO RIGHT
// NOT ONLY FOR THE ENTIRE SUB ARRAY
// EITHER FOR EACH SUB ARRAY THAT
// IS BEING CREATED FROM THE LEFT TO RIGHT
// FOR EXAMPLE [2, -1], k = 2
// THE SUBARRAY n[0] ONLY THE FIRST
// ELEMENT NEEDS A SUBARRAT THAT SUMS UP TO
// 0, WHICH IS OUR BASE CASE

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<int, int> pfxCount = {{0, 1}};

        int prefixSum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int diff = prefixSum - k;
            res += pfxCount.contains(diff) ? pfxCount[diff] : 0;
            pfxCount[prefixSum]++;
        }
        return res;
    }
};