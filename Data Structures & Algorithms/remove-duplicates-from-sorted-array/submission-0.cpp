class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int L = 1;
        for (int R = 1; R < n; R++) {
            if (nums[R] != nums[R - 1]) {
                nums[L] = nums[R];
                L++;
            }
        }
        return L;
    }
};