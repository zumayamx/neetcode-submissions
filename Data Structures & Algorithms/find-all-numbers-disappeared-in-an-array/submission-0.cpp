class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique;
        
        for (int i = 1; i <= n; i++)
        {
            unique.insert(i);
        }
        for (int num : nums)
        {
            unique.erase(num);
        }
        
        vector<int> res(unique.begin(), unique.end());
        return res;
    }
};