class Solution {
public:
    void sortColors(vector<int>& nums) {
        // You need to known the max value
        // that could appear in the array
        // to initialize it.
        vector<int> ocurr(3, 0);
        for (int e : nums)
        {
            ocurr[e]++;
        }

        int k = 0;
        for (int i = 0; i < (int)ocurr.size(); i++)
        {
            for (int j = 0; j < ocurr[i]; j++)
            {
                nums[k] = i;
                k++;
            }
        }
    }
};