class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int currSum = 0;
        int minLen = INT_MAX;
        int L = 0;

        for (int R = 0; R < n; R++)
        {
            currSum += nums[R];
            while (currSum >= target)
            {
                minLen = min(minLen, R - L + 1);
                currSum -= nums[L];
                L++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};