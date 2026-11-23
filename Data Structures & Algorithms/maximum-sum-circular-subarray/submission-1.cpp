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
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubArray(nums);
        if (maxSum < 0) return maxSum;

        int totalSum = 0;
        for (int& e : nums) totalSum += e;

        int currSum = 0;
        int minSum = INT_MAX;
        for (int & e : nums)
        {
            if (currSum > 0) currSum = 0;
            
            currSum += e;
            if (currSum < minSum) minSum = currSum;
        } 

        return max(maxSum, totalSum - minSum);
    }
};