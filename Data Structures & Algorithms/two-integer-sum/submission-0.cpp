class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> valueIndex;

        for (int i = 0; i < n; i++)
        {
            if (valueIndex.find(target - nums[i]) != valueIndex.end())
            {
                return { valueIndex[target - nums[i]], i };
            }
            else
            {
                valueIndex[nums[i]] = i;
            }
        }
    }
};
