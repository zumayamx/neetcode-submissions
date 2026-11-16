class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> ocurr;
        for (int n : nums)
        {
            ocurr[n]++;
            if (ocurr[n] == 2) return true;
        }
        return false;
    }
};