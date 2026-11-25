class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return 1;

        int L = 2;
        for (int R = 2; R < n; R++)
        {
            if (nums[R] != nums[L - 1] || nums[R] != nums[L - 2])
            {
                swap(nums[R], nums[L]);
                L++;
            }
        }
        return L;
    }
};