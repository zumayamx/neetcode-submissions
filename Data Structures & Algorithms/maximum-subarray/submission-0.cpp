class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int& e : nums) {
            if (currSum < 0) currSum = 0;

            currSum += e;
            if (currSum > maxSum) maxSum = currSum;
        }
        return maxSum;
    }
};
