// TAKE CARE ABOUT THE EDGE CASES
// A SIMPLE CONDITION IS ENOUGH
// TO NOT ENTER IN TROUBLE WITH
// THE INDEXES, TAKE CARE ABOUT
// THE CONDITION, THE MOST LEFT
// INDEX, THAT IMPLIES DO
// THE POSTFIX SUM FIRST THEN
// THE PREFIX SUM

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> postfixSums(n);
        for (int i = n - 1; i >= 0; i--) {
            postfixSums[i] = i == n - 1 ? 0 : postfixSums[i + 1] + nums[i + 1];
        }

        vector<int> prefixSums(n);
        for (int i = 0; i < n; i++) {
            prefixSums[i] = i == 0 ? 0 : prefixSums[i - 1] + nums[i - 1];
            if (postfixSums[i] == prefixSums[i]) return i;
        }

        return -1;
    }
};