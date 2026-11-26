class NumArray {
    vector<int> prefixSums;

   public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for (int& n : nums) {
            total += n;
            prefixSums.push_back(total);
        }
    }

    int sumRange(int left, int right) {
        int rightPrefix = prefixSums[right];
        int leftPrefix = left > 0 ? prefixSums[left - 1] : 0;
        return rightPrefix - leftPrefix;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */