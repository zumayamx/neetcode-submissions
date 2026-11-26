class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> postfixSums(n);
        for (int i = n - 1; i >= 0; i--) {
            postfixSums[i] = i == n - 1 ? 0 : postfixSums[i + 1] + nums[i + 1];
        }

        cout << "postSums: ";
        for (int& e : postfixSums) {
            cout << e << " ";
        }
        cout << endl;

        vector<int> prefixSums(n);
        for (int i = 0; i < n; i++) {
            prefixSums[i] = i == 0 ? 0 : prefixSums[i - 1] + nums[i - 1];
            if (postfixSums[i] == prefixSums[i]) return i;
        }

        cout << "prefSums: ";
        for (int& e : prefixSums) {
            cout << e << " ";
        }
        cout << endl;

        return -1;
    }
};