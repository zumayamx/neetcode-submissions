class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> prefixProduct(n);
        for (int i = 0; i < n; i++) {
            prefixProduct[i] = i == 0 ? 1 : nums[i - 1] * prefixProduct[i - 1];
        }

        vector<int> postfixProduct(n);
        for (int i = n - 1; i >= 0; i--) {
            postfixProduct[i] = i == n - 1 ? 1 : nums[i + 1] * postfixProduct[i + 1];
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(prefixProduct[i] * postfixProduct[i]);
        }
        return res;
    }
};
