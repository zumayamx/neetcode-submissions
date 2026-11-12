/*
* I think, one approach could be the decision tree, but now the numbers
* could have one more decision, which is to select themselves again and again.
*
* The stop conditions could be, if we have used all numbers from the array or
* if the sum of the current subset is greater than target or if the current sum
* is equal to target.
*  
* We need a global list to save all valid subset based on the condition.
* I think is a decision tree with two decisions:
* 1. Select the same number again.
* 2. Select the next number.
* 3. No select the next number (backtrack).
*
* Pseudocode:
* def dfs(nums, res, sub, target, i)
*   sub.push_back(nums[i]);
*   if sum(sub) > target: 
*       return;
*   else if sum(sub) == target: 
*       res.push_back(sub)
*       return;
*
*   dfs(nums, res, sub, i)
*   sub.pop_back()
*   dfs(nums, res, sub, i + 1)
*   return
*   
*
* For example:
* Input:
* nums = [2,5,6,9]
* target = 9
*
* Call 1:
* res = []
* sub = []
* i = 0
* sub.push_back(nums[i]);
* sub = [2]
* Call 2:
* res = []
* sub = []
* i = 0
* sub.push_back(nums[i]);
* sub = [2, 2]
* The same until Call 5:
* res = []
* sub = []
* i = 0
* sub.push_back(nums[i]);
* sub = [2, 2, 2, 2, 2]
* sum(sub) = 10 > target = 10 > 9, then return to call 4.
* Call 4:
* res = []
* sub = []
* i = 0
* sub.push_back(nums[i]);
* sub = [2, 2, 2, 2, 2]
* Pop the last element of the sub
* sub.pop_back()
* sub = [2, 2, 2, 2]
* Call the function again with i + 1, that would be Call 6:
* res = []
* sub = [2, 2, 2, 2]
* i = 1
* Add the element i to the sub, that is 5.
* sub = [2, 2, 2, 2, 5]
* sum(sub) = 13 > 9, yes, then return to Call
* Here exists a bug, because the pop()
* is cleaning what the child recursive call
* is adding to the sub array, not what this
* instance of the function is adding it.
*
*
* New approach with feedback of AI:
* Move the checks, equal, greater or i > nums.size
* to the begining of the function. There is no
* problem with sum(sub) to return 0, becuase by 
* the constrints target could not be 0, therefore
* if the sum returns 0, that means I haven't selected
* anything yet.
*
* Whith that in mind, we can modify our pseudocode:
*
* def dfs(nums, res, sub, target, i)
*   if sum(sub) > target: 
*       return;
*   else if sum(sub) == target: 
*       res.push_back(sub)
*       return;
*   if i == nums.size:
*       return
*
*   sub.push_back(nums[i])
*   dfs(nums, res, sub, i)
*   sub.pop_back()
*   dfs(nums, res, sub, i + 1)
*   return
*
*
*/

class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int rem, int i)
    {
        if (rem < 0) return;
        else if (rem == 0)
        {
            res.push_back(subset);
            return;
        }
        if (i == (int)nums.size()) return;

        subset.push_back(nums[i]);
        dfs(nums, res, subset, rem - nums[i], i);
        subset.pop_back();
        dfs(nums, res, subset, rem, i + 1);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, res, subset, target, 0);
        return res;
    }
};
